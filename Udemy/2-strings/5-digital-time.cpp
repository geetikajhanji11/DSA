#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;


string convert_to_digital_time(int minutes){
    
    string time;

    int hrs = minutes / 60;
    int mins = minutes % 60;

    string h = to_string(hrs);
    string m = to_string(mins);

    time = h + ":" + (mins < 10 ? "0" : "") + m;

    return time;

}

// main function
int main() {

    cout<<convert_to_digital_time(125)<<endl;
    cout<<convert_to_digital_time(155)<<endl;
    cout<<convert_to_digital_time(1180)<<endl;

    return 0;
}

