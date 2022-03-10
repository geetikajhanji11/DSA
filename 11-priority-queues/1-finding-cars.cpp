/******************************************************************************

You are given N cartesian points in a 2D plane. Each represents the location
of the car. You are standing at origin, you want to know the names of nearest
k cars.

Sample Input:
    N = 5, K = 3
    C1 1 1
    C2 2 1
    C3 3 2
    C4 0 1
    C5 2 3
    
Sample Output:
    C4
    C1
    C2

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include<algorithm>
using namespace std;



class Car {
    public:
    string id;
    int x, y;
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int distance() {
        return x*x + y*y;
    }
};

class CarCompare {
public:
    bool operator()(Car A, Car B) {
        return A.distance() < B.distance(); // max heap
    }
};

bool sortByDistance(Car a, Car b) {
    return a.distance() < b.distance();
}

vector<Car> nearestCars(vector<Car> cars, int k) {
    
    // cretae max heap and insert k cars
    priority_queue<Car, vector<Car>, CarCompare> heap(cars.begin(), cars.begin() + k);
    
    // check rest of the cars
    for(int i=k; i<cars.size(); i++) {
        Car currentCar = cars[i];
        Car heapTopCar = heap.top();
        if(currentCar.distance() < heapTopCar.distance()) {
            heap.pop();
            heap.push(currentCar);
        }
    }
    
    // store the cars in new vector
    vector<Car> result;
    while(!heap.empty()) {
        result.push_back(heap.top());
        heap.pop();
    }
    
    // sort by distance
    sort(result.begin(), result.end(), sortByDistance);
    
    return result;
}

int main() {

    vector<Car> cars{
        Car("C1", 1, 1),
        Car("C2", 2, 1),
        Car("C3", 3, 2),
        Car("C4", 0, 1),
        Car("C5", 2, 3)
    };
    int n = cars.size();
    int k = 3;

    vector<Car> result = nearestCars(cars, k);
    for(Car car : result) {
        cout<<car.id<<endl;
    }

    return 0;
}
