#include "input.h"

bool Input(vector<DATA> &myData, const char *FileName) 
{
    ifstream in(FileName);

    if(!in){
        cout << "Error input file" << endl;
        return false;
    }

    DATA d;
    while( in>>d.x && in>>d.y && in>>d.z && in>>d.u ){
        myData.push_back(d);
    }
    return true;
}
