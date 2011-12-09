#ifndef input_H_
#define input_H_


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct DATA{
    DATA(double c1 = 0, double c2 = 0, double c3 = 0, double c4 = 0, double v1=0)
               :x(c1),y(c2),z(c3),u(c4),c_id(v1){} 
    
    double x;
    double y;
    double z;
    double u;
    int c_id;

    //~DATA() { cerr << "DATA destruct" << endl;}
};

bool Input(vector<DATA> &myData, const char *FileName); 

#endif
