#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "DE.h"
#include <iomanip>

using namespace std;

int main(int argc, char const* argv[])
{
    
    srand(time(NULL));

    vector<DATA>MyData;
    if(!Input(MyData, "iris.data")){
        cout << " ERROR File Input" << endl;
        return 0;
    }

    if(argc!=4){
        cout << endl;
        cout << "Usage: ./program <population> <cluster_number_MAX> <MaxIter>";
        cout << endl;
        cout << endl;
        return 1;
    }

    for (int i = 0; i < 1; i++) {
        DE Gen(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), MyData);
        //argv[1] = psize, argv[2] = cNum, argv[3] = Maxiter 
    }



//    int n;
//    cout << MyData.size();
//    for (n = 0; n < MyData.size(); n++) {
//        cout << setw(5) << MyData[n].x << " " <<  setw(5) <<  MyData[n].y  
//             << " " << setw(5) << MyData[n].z 
//             << " " << setw(5) << MyData[n].u 
//             << " " << setw(5) << MyData[n].c_id << endl;
//    }
    
    return 0;
}
