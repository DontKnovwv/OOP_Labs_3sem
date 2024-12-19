#include <iostream>

#include "Vector.h"
#include "point.h"
#include "figure.h"
#include "hexagon.h"
#include "rhomb.h"
#include "pentagon.h"

using namespace std;

int main(){
    auto ptr = make_shared<int>();
    delete ptr.get();
}
