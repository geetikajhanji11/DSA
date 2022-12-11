/*******************************************************************
The idea is:

The ZERO comes from 10.
The 10 comes from 2 x 5
And we need to account for all the products of 5 and 2. 
likes 4×5 = 20 ...

So, if we take all the numbers with 5 as a factor, 
we'll have way more than enough even numbers to pair 
with them to get factors of 10

Example One
-----------
How many multiples of 5 are between 1 and 23? 

There is 5, 10, 15, and 20, for four multiples of 5. 
Paired with 2's from the even factors, 
this makes for four factors of 10, so: 23! has 4 zeros.

Example Two
-----------
How many multiples of 5 are there in the numbers from 1 to 100?

because 100 ÷ 5 = 20, so, there are twenty multiples of 5 
between 1 and 100.

but wait, actually 25 is 5×5, so each multiple of 25 has an 
extra factor of 5, e.g. 25 × 4 = 100，which introduces extra of zero.

So, we need know how many multiples of 25 are between 1 and 100? 
Since 100 ÷ 25 = 4, there are four multiples of 25 between 1 and 100.
Finally, we get 20 + 4 = 24 trailing zeroes in 100!

The above example tell us, we need care about 
    5, 5×5, 5×5×5, 5×5×5×5 ....
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// ************** DISCUSS SOLUTION **************
// O(logn)
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long i=5; n/i>0; i=i*5){
            result += (n/i);
        }
        return result;
    }
};

// ************** MY SOLUTION **************
// o(nlogn)
class Solution {

    int factors(int num, int digit) {
        int count = 0;
        while(num % digit == 0) {
            count++;
            num /= digit;
        }
        return count;
    }

public:
    int trailingZeroes(int n) {
        int count_2 = 0;
        int count_5 = 0;

        for(int i=1; i<=n; i++) {
            count_2 += factors(i, 2);
            count_5 += factors(i, 5);
        }

        return min(count_2, count_5);
    }
};