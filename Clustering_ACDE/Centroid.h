#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class vertex {
    public:
        vertex(double c1 = 0, double c2 = 0, double c3 = 0, double c4 = 0, double v1=0)
               :x(c1),y(c2),z(c3),u(c4),t(v1){} 
        // give initial value to vector , because we do not use push_back
        // we use assign to put the value into vector
        double x;   //position
        double y;
        double z; 
        double u;
        double t; // Activation threshold
};

//vector<vertex> cent;

