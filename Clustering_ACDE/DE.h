#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "input.h"
#include "POP.h"
#include <time.h>
#include <math.h>

using namespace std;

class DE {

public:
    DE(){}
    //~DE(){ cerr << "DE destruct" << endl;}
    DE(int p, int c, int i, vector<DATA> MyData):pSize(p),cNum(c),
                            MaxIter(i),population(p,c),mutation(pSize, cNum){Iteration(MyData, MaxIter);} 
    void Init(vector<DATA> MyData);
    void Assign();
    void AEC();  //Avoiding Erroneous Chromesome
    void Mutant(int iter);
    void Crossover();
    void Fit();
    void Select();
    void Iteration(vector<DATA> MyData, int MaxIter);

private:
    int pSize;
    int cNum;
    int MaxIter;
    double F;
    //vector<DATA> MyData;
    vector<POP> population;
    vector<POP> mutation;

};


