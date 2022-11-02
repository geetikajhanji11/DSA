/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

list<int> toBinary(int n) {
    list<int> binary;
    while (n > 0) {
        binary.push_front(n % 2);
        n = n / 2;
    }
    return binary;
}

list<int> addTwoLists(list<int> &a, list<int> &b) {
    auto revit_a = a.rbegin();
    auto revit_b = b.rbegin();

    list<int> result;
    int carry = 0;

    while(revit_a != a.rend() && revit_b != b.rend()) {
        int sum = *revit_a + *revit_b + carry;
        carry = sum / 2;
        sum = sum % 2; 

        result.push_front(sum);

        revit_a++;
        revit_b++;
    }

    while(revit_a != a.rend()) {
        int sum = *revit_a + carry;
        carry = sum / 2;
        sum = sum % 2; 

        result.push_front(sum);
        revit_a++;
    }

    while(revit_b != b.rend()) {
        int sum = *revit_b + carry;
        carry = sum / 2;
        sum = sum % 2; 

        result.push_front(sum);
        revit_b++;
    }

    if(carry != 0) {
        result.push_front(carry);
    }

    return result;
}

list<int> multiplyBy10(list<int> binary) {
    list<int> a = binary;
    list<int> b = binary;

    a.push_back(0);

    b.push_back(0);
    b.push_back(0);
    b.push_back(0);

    return addTwoLists(a, b);
}

// "1234576746464"
string binaryEquiv(string integerString) {

    int n = integerString.size();
    list<int> result = toBinary(integerString[0] - '0');

    for(int i=1; i<n; i++) {
        int num = integerString[i] - '0';
        list<int> numBinary = toBinary(num);

        list<int> resultMult10 = multiplyBy10(result);
        result = addTwoLists(resultMult10, numBinary);
    }
    
    string str = "";
    for(int num : result) {
        str += to_string(num);
    }

    return str;
}


int main() {


    string integerString = "1234576746464";

    // 1
    // 1*10 + 2 = 12
    // 12*10 + 3 = 123
    // 123*10 + 4 = 1234
    // ...

    cout<<binaryEquiv(integerString);

    return 0;
}
