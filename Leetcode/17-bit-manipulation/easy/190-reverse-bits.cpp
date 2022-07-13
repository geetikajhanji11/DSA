#include<bits/stdc++.h>
using namespace std;

uint32_t get_ith_bit(uint32_t num, int i) {
    uint32_t mask = 1<<i; 
    uint32_t arbitary = num & mask; 
    if(arbitary == 0) return 0;
    else return 1;
}

void set_ith_bit(uint32_t &num, int i) {
    uint32_t mask = 1<<i;
    num = num | mask;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i=0; i<32; i++) {
        uint32_t bit = get_ith_bit(n, i);
        if(bit == 1) {
            set_ith_bit(ans, 31-i);
        }
    }
    return ans;
}

int main() {

    return 0;
}