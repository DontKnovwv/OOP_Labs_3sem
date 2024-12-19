#include <iostream>

#include "include/Vector.h"
#include "include/point.h"
#include "include/figure.h"
#include "include/hexagon.h"
#include "include/rhomb.h"
#include "include/pentagon.h"

using namespace std;

int main(){
    Rhomb fig1;
    Hexagon fig2;
    Vector arr;

    arr.push_back(&fig1);
    arr.push_back(&fig2);

    for (size_t i = 0; i < arr.size(); ++i){
        cout << *arr[i] << endl;;
    }

    arr.remove(0);

        for (size_t i = 0; i < arr.size(); ++i){
        cout << *arr[i] << endl;
    }
}
