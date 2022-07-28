/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********************** APPROACH - 1 **********************
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1; 
    int high = *max_element(piles.begin(), piles.end());

    int result = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        long int hours = 0;
        for(int pile : piles) {
            hours += ceil(double(pile) / mid);
        }

        if(hours <= h) { // need to eat less bananas to reduce time, search left
            result = min(result, mid);
            high = mid - 1;
        } else { // need to eat more bananas, search right
            low = mid + 1; 
        }
    }

    return result;
}

// ********************** APPROACH - 2 **********************
// bool koko_can_finish(vector<int> piles, int k, int h) {
//     int i = 0;
//     while(h != 0 && i < piles.size()) {
//         piles[i] = piles[i] - k;
//         if(piles[i] <= 0) i++;
//         h--;
//     }
//     return i == piles.size();
// }

// int minEatingSpeed(vector<int>& piles, int h) {

//     int low = 1;
//     int high = *max_element(piles.begin(), piles.end());

//     int ans = high;

//     while(low <= high) {
//         int mid = (low + high) / 2;
//         cout<<"\nmid = "<<mid;
//         if(koko_can_finish(piles, mid, h)) {
//             ans = min(ans, mid);
//             high = mid - 1;
//             cout<<", yes she can finish. Now ans = "<<ans;
//         } else {
//             low = mid + 1;
//         }
//     }
    
//     cout<<"\nfinal ans = "<<ans;
//     return ans;

// }

int main() {

    vector<int> piles = {312884470};
    int ans = minEatingSpeed(piles, 312884469);
    cout<<"\nfinal nas = "<<ans;
    return 0;
}

