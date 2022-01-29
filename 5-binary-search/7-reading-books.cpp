/**************************************************************

READING BOOKS

Given number of pages in "n" different books and "m" students.
The books are arranged in any order (not necessarily ascending) 
of number of pages. Every student is assigned to read some
consecutive segment of books. The task is to assign books in 
such a way that the maximum number of pages assigned to a student 
is minimum.

Find the maximum number of pages that a student will have to read.

Input:
    students = 2
    books = {10, 20, 30, 15}

Output:
    45

Explanation:

    There are 2 number of students. 
    Books can be distributed in following fashion:

    1)  [10] and [20, 30, 15]
        Max number of pages is allocated to student 2 with 65 pages

    2)  [10, 20] and [30, 15]
        Max number of pages is allocated to student 2 with 30 + 15 = 45 pages

    3)  [10, 20, 30] and [15]
        Max number of pages is allocated to student 1 with 60 pages

    Of the 3 cases, Option 2 has minimum pages = 45

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

// checks if everyone is able to read pages >= targeted pages
// (i.e., able to form a partition of m subarrays)
bool canEachReadMinPages(vector<int> arr, int m, int targetPages) {
    int subarraySum = 0;
    int students = 1;
    for(int num : arr) {
        
        if(subarraySum + num > targetPages) {
            students++;
            subarraySum = num;
            if(students > m) return false;
        } else {
            subarraySum += num;
        }
    }

    return true;
}


int minPages(vector<int> books, int m){

    int answer = INT_MAX;

    int low = 0;
    int high = 0;
    for(int pages : books) {
        high += pages;
        low = max(low, pages);
    }

    while(low <= high) {
        int mid = (low + high) / 2;

        // minimize the pages, go left
        if(canEachReadMinPages(books, m, mid)) {
            answer = min(answer, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

// main function
int main() {

    vector<int> books{10, 20, 30, 15};
    int students = 2;
    
    cout<<minPages(books, students);

}