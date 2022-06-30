/*******************************************************************
 * GET, SET, CLEAR, UPDATE ITH BIT
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// ************** FIND ITH BIT ****************** //
int get_ith_bit(int num, int i) {

    // move the position of the bits 5 positions to the left side 
    // and add zeroes to the empty space created at the  right side 
    // after shifting the bits.
    /*
        ----- i = 5 -----
        309     => 100110101
        mask    => 000100000 (1 is at 5th position)
    */
    int mask = 1<<i; 
    int arbitary = num & mask; // 32 (000100000)

    if(arbitary == 0) return 0;
    else return 1;
    
}

// ************** SET ITH BIT ****************** //
// make 0 => 1
int set_ith_bit(int num, int i) {
    /*
        ----- i = 7 -----
        309     => 100110101
        mask    => 010000000 (1 is at 7th position)
    */
    int mask = 1<<i;
    int ans = num | mask; // 110110101 (437)
    return ans;
}

// ************** CLEAR ITH BIT ****************** //
// make 1 => 0
int clear_ith_bit(int num, int i) {
    /*
        ----- i = 4 -----
        309     =>   100110101
        mask    => ~(000010000) (1 is at 4th position)
                =>   111101111
    */
   int mask = ~(1<<i);
   int ans = num & mask;
   return ans;
}

// ************** UPDATE ITH BIT ****************** //
int update_ith_bit(int num, int i, int value) {
    num = clear_ith_bit(num, i);
    int mask = value<<i;
    int ans = num | mask;
    return ans;
}

int main() {

    int n = 309, i = 6, ans;

    cout<<"\n\n 309 => 100110101\n";

    ans = get_ith_bit(n, i);
    cout<<"\t"<<i<<"th bit = "<<ans;

    ans = set_ith_bit(n, i);
    cout<<"\n\tAfter setting "<<i<<"th bit = "<<ans;
    
    ans = clear_ith_bit(n, i);
    cout<<"\n\tAfter clearing "<<i<<"th bit = "<<ans;

    ans = update_ith_bit(n, i, 1);
    cout<<"\n\tAfter updating "<<i<<"th bit = "<<ans;

    return 0;

}