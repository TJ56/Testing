#ifndef POP_H_
#define POP_H_ 

#include "Centroid.h"
#include "input.h"

using namespace std;

class POP {
    public:
        POP(){}
        //~POP(){ cerr << "POP destruct" << endl;}
        POP(int c):cNum(c),cent(cNum){}   //cNum = K_max
        void genCent();
        void genCentA();
        void genAssign();
        void chkAEC(); 
        //Avoiding Erroneous Chromosome
        void genFit();
        void setgN(int gn);
        friend POP operator+(const POP &op1, const POP &op2);
        friend POP operator-(const POP &op1, const POP &op2);
        friend POP operator*(double F, const POP &op2);
        friend POP operator%=(POP &op1, const POP &op2);
        POP& operator=(const POP& op1);

        void getCentV(int i);
        vector<DATA> getData();
        void Input(const vector<DATA> &_data);
        double getFit();
        void Output();

        
        
        //vector <DATA> MyData;
    private:
        int cNum;
        int actNum;
        vector <double> mindtc;
        vector < int  > countID;  //count data points in each cluster 
        vector <vertex> cent;
        vector <vertex> centA; //active cent
        vector <DATA> MyData;
        int gN;
        double Fit_CS_Measure;

};



#endif

