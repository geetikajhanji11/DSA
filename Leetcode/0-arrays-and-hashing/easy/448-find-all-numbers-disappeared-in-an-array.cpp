/*******************************************************************
WALKTHROUGH (STEP-WISE)

Given => [4,3,2,7,8,2,3,1]
Insert dummy 0 at beginning 
It becomes => [0,4,3,2,7,8,2,3,1]

--------------------------------
index => [0,[1],2,3,4,5,6,7,8]
nums  => [0,[4],3,2,7,8,2,3,1]

At i=1, 
nums[1] = 4... 
cycle starts

 *  index => [0,1,2,3, 4,5,6,7,8] (visiting 4 now...)
    nums  => [0,4,3,2,-7,8,2,3,1] (mark nums[4] = 7 as -ve [-7])

 *  index => [0,1,2,3, 4,5,6, 7,8] (visiting 7 now...)
    nums  => [0,4,3,2,-7,8,2,-3,1] (mark nums[7] = 3 as -ve [-3])

 *  index => [0,1,2, 3, 4,5,6, 7,8] (visiting 3 now...)
    nums  => [0,4,3,-2,-7,8,2,-3,1] (mark nums[3] = 2 as -ve [-2])

 *  index => [0,1, 2, 3, 4,5,6, 7,8] (visiting 2 now...)
    nums  => [0,4,-3,-2,-7,8,2,-3,1] (mark nums[2] = 3 as -ve [-3])

 *  end of cycle... as nums[3] = -2. This means 3 has 
    already been visited.

--------------------------------
index => [0,1,[2], 3, 4,5,6, 7,8]
nums  => [0,4,[-3],-2,-7,8,2,-3,1]

At i=2, 
nums[2] = -3 (already visited) 

--------------------------------
index => [0,1, 2,[3], 4,5,6, 7,8]
nums  => [0,4,-3,[-2],-7,8,2,-3,1]

At i=3, 
nums[3] = -2 (already visited) 

--------------------------------
index => [0,1, 2, 3,[4],5,6, 7,8]
nums  => [0,4,-3,-2,[-7],8,2,-3,1]

At i=4, 
nums[4] = -7 (already visited) 

--------------------------------
index => [0,1, 2, 3, 4,[5],6, 7,8]
nums  => [0,4,-3,-2,-7,[8],2,-3,1]

At i=5, 
nums[5] = 8... 
cycle starts

 *  index => [0,1, 2, 3, 4,5,6, 7, 8] (visiting 8 now...)
    nums  => [0,4,-3,-2,-7,8,2,-3,-1] (mark nums[8] = 1 as -ve [-1])

 *  index => [0, 1, 2, 3, 4,5,6, 7, 8] (visiting 1 now...)
    nums  => [0,-4,-3,-2,-7,8,2,-3,-1] (mark nums[1] = 4 as -ve [-4])

 *  end of cycle... as nums[4] = -7. This means 4 has 
    already been visited.

--------------------------------
index => [0, 1, 2, 3, 4,5,6, 7, 8] 
nums  => [0,-4,-3,-2,-7,8,2,-3,-1]

At i=6, 
nums[6] = 2... 
cycle starts

 *  index => [0, 1, 2, 3, 4,5, 6, 7, 8] (visiting 6 now...)
    nums  => [0,-4,-3,-2,-7,8,-2,-3,-1] (mark nums[6] = 2 as -ve [-2])

 *  end of cycle... as nums[2] = -3. This means 2 has 
    already been visited.

--------------------------------
index => [0, 1, 2, 3, 4,5,6, 7, 8] 
nums  => [0,-4,-3,-2,-7,8,2,-3,-1]

At i=7, 
nums[7] = -3 (already visited) 

--------------------------------
index => [0, 1, 2, 3, 4,5,6, 7, 8] 
nums  => [0,-4,-3,-2,-7,8,2,-3,-1]

At i=8, 
nums[8] = -1 (already visited) 

--------------------------------
index => [0, 1, 2, 3, 4,[5],[6], 7, 8] 
nums  => [0,-4,-3,-2,-7,[8],[2],-3,-1]

Now traverse the whole array and include
those i where nums[i] > 0 (not visited)
--------------------------------


OTHER EXAMPLES

[0, 1,2]
[0,-1,1]

[0, 1,2, 3, 4, 5,6,7, 8, 9]
[0,-9,5,-3,-1,-8,4,4,-4,-4]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // make current array 1 indexed by inserting
        // a dummy number 0 at the beginning
        vector<int> temp = {0};
        temp.insert(temp.end(), nums.begin(), nums.end());
        nums = temp;

        // start from the index=1 element of nums
        for(int i=1; i<nums.size(); i++) {
            int nextIdx = nums[i]; 

            // already been visited
            if(nextIdx < 0) continue; 

            // visit all numbers in current cycle
            while(nums[nextIdx] > 0) { 
                int tempIdx = nums[nextIdx]; 
                nums[nextIdx] *= (-1); // marking this number as visited
                nextIdx = tempIdx; 
            }
        } 

        vector<int> result;
        for(int i=1; i<nums.size(); i++) {
            int num = nums[i];
            if(num > 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};