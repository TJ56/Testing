#include "POP.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;

double uniRand(){
    return rand() / double(RAND_MAX);
}

void reinitial(vector<DATA> &MyData, vector<vertex> &centA){
//    cout << endl;
//    cout << "  ReAssign c_id !  ";
//    srand(unsigned (time (NULL)));
    vector<int> RandV;
    vector<int>::iterator it;

    for (int i = 0; i < MyData.size(); i++) {
        RandV.push_back(i);
    }

    random_shuffle(RandV.begin(), RandV.end());
    random_shuffle(RandV.begin(), RandV.end(), p_myrandom);

//    cout << "floor : " << floor(MyData.size()/centA.size()) << endl;

//    cout << "RandV contains : ";
//
//    for(it = RandV.begin(); it!=RandV.end(); ++it)
//        cout << " " << *it;
//
//    cout << endl;

    int counter = 0;
    for (int j = 0; j < centA.size(); j++) {
        //cout << "Step : " << counter << endl;

        for (int i = 0; i < RandV.size(); i++) {
            //cout << " " << RandV[i]; 
            MyData[RandV[i]].c_id = counter;
        }

        //cout << endl;
        RandV.erase(RandV.begin(), RandV.begin() + floor(MyData.size()/centA.size()));

        counter++;
    }

//        cout << endl;
    vector <int> countID(centA.size());
//    cout <<" centA size : " << centA.size() << endl;
    for (int j = 0; j < MyData.size(); j++) {
        countID[MyData[j].c_id]++;           
//        cout << MyData[j].c_id << " ";
    } 

//    cout << endl << " CountID : ";
//    for (int i = 0; i < centA.size(); i++) {
//        cout << countID[i] << "  ";
//    }
//    cout << endl;


}

void POP::Input(const vector<DATA> &_data){
    
    MyData.assign(_data.begin(), _data.end());
}

void POP::genCent(){

    //MyData.assign(_data.begin(), _data.end());
    cent.clear();
    int actNum = 0 ;    //active centroid number
    for (int i = 0; i < cNum; i++) {
        vertex test;
        int n = rand()%MyData.size();
        test.x = MyData[n].x;
        test.y = MyData[n].y;
        test.z = MyData[n].z;
        test.u = MyData[n].u;
        test.t = uniRand();

//        cent[i] = test;

        for (int k = 0; k < i; k++) {   //Avoid same Centroid
            if(cent[k].x == test.x && cent[k].y == test.y &&    
               cent[k].z == test.z && cent[k].u == test.u ){

                int n = rand()%MyData.size();
                test.x = MyData[n].x;
                test.y = MyData[n].y;
                test.z = MyData[n].z;
                test.u = MyData[n].u;
                test.t = uniRand();

            }

        }

        cent[i] = test;

        if(i%cNum== 0){
            cout << "================Individual==================" << endl;
        }
//        cout << setw(5) << cent[i].x << " , " << setw(3) << cent[i].y << " , "
//             << setw(3) << cent[i].z << " , " << setw(3) << cent[i].u << " , "
//             << setw(3) << cent[i].t << endl;

        if(cent[i].t > 0.5){
            actNum++;
            centA.push_back(cent[i]);
        }
//        if (actNum < 2) {
//        int a = rand()%cNum;
//        int b = rand()%cNum;
//        //cout << a << " " << b << endl;
//        
//        double R1 = (uniRand() + 1)/2;
//        double R2 = (uniRand() + 1)/2;
//        cout << R1 << " " << R2 << endl;
//        cent[a].t = R1;
//        cent[b].t = R2;
//         
//        }
//        if(cent[i].t > 0.5){
//            actNum++;
//            centA.push_back(cent[i]);
//        }
 
    }

    for (int i = 0; i < cNum; i++) {
       if (centA.size() < 2) {
            centA.clear();
            int a = rand()%cNum;
            int b = rand()%cNum;
            while (b == a)
                b = rand()%cNum;
            //cout << a << " " << b << endl;
            
            double R1 = (uniRand() + 1)/2;
            double R2 = (uniRand() + 1)/2;
            //cout << R1 << " " << R2 << endl;
            cent[a].t = R1;
            cent[b].t = R2;
             
            centA.push_back(cent[a]);
            centA.push_back(cent[b]);
        }
//        if(cent[i].t > 0.5){
//            actNum++;
//            centA.push_back(cent[i]);
//        }
 
    }
//    if (actNum < 2) {
//        int a = rand()%cNum;
//        int b = rand()%cNum;
//        //cout << a << " " << b << endl;
//        
//        double R1 = (uniRand() + 1)/2;
//        double R2 = (uniRand() + 1)/2;
//        cout << R1 << " " << R2 << endl;
//        cent[a].t = R1;
//        cent[b].t = R2;
//         
//    }
//    for (int i = 0; i < cNum; i++) {
//     if(cent[i].t > 0.5){
//            actNum++;
//            centA.push_back(cent[i]);
//        }
//    }

            cout << "Original active cluster number : " << actNum << endl;
    //cout << "===========================" << endl;
    
        for(int i = 0; i < centA.size(); i++){
        cout << setw(5) << centA[i].x << "  " << setw(3)<< centA[i].y << "  " 
             << setw(3) << centA[i].z << "  " << setw(3)<< centA[i].u << "  " 
             << setw(3) << centA[i].t << endl;
        }

}

void POP::genCentA(){
    centA.clear();
    for (int i = 0; i < cNum; i++) {
        if(cent[i].t > 0.5){
            centA.push_back(cent[i]);
        }
    }

}

void POP::getCentV(int i){
     if(i%cNum== 0){
            cout << "================Individual==================" << endl;
     }
     cout << setw(15) << cent[i].x << " , " << setw(15) << cent[i].y << " , "
          << setw(15) << cent[i].z << " , " << setw(15) << cent[i].u << " , "
          << setw(15) << cent[i].t << endl;
}

vector<DATA> POP::getData(){
    return MyData;
}

void POP::genAssign(){
//    int actNum = 0;
//    for (int i = 0; i < cNum; i++) {        
//        if(cent[i].t > 0.5)
//            actNum++;
//    }
    centA.clear();
    for (int i = 0; i < cNum; i++) {
        if(cent[i].t > 0.5){
            centA.push_back(cent[i]);
        }
    }
//    cout << " Look at : " << centA.size() << endl;
    for (int i = 0; i < cNum; i++) {
       if (centA.size() < 2) {
            centA.clear();
            int a = rand()%cNum;
            int b = rand()%cNum;
            while (b == a)
                b = rand()%cNum;
            //cout << a << " " << b << endl;
            
            double R1 = (uniRand() + 1)/2;
            double R2 = (uniRand() + 1)/2;
            cout << "reassign two centroid! " << endl;
            cent[a].t = R1;
            cent[b].t = R2;
             
            centA.push_back(cent[a]);
            centA.push_back(cent[b]);
        }
       //else 
       //    genCentA(); //mark!!!!!!!!!!
           
    }
//    cout << " cNum : " << cNum << endl;
//    cout << " actNum : " << centA.size() << endl;
//    cout << " Look at 2 : " << centA.size() << endl;
    double dtc[centA.size()];
    vector <double> mindtc(MyData.size());

   
    //for (int j = 0; j < centA.size(); j++) {
        for (int i = 0; i < MyData.size(); i++) {
            for (int j = 0; j < centA.size(); j++) {
            dtc[j] = pow((MyData[i].x - centA[j].x),2) + 
                     pow((MyData[i].y - centA[j].y),2) +          
                     pow((MyData[i].z - centA[j].z),2) +
                     pow((MyData[i].u - centA[j].u),2) ;   //SSE
            if(j == 0){
                mindtc[i] = dtc[0];
                MyData[i].c_id = 0;
            }
            if(dtc[j] < mindtc[i]){
                mindtc[i] = dtc[j];
                MyData[i].c_id = j;
            }

            
        }
    }
    
//            cout << "dtc : " << dtc[0] << endl;
//            cout << "dtc : " << dtc[1] << endl;
//            cout << "dtc : " << dtc[2] << endl;

//    for (int i = 0; i < MyData.size(); i++) {
//        cout << mindtc[i] << "       ";
//        cout << MyData[i].c_id << " ";

//        cout << endl;
        
//    }
//
//    double sse = 0;
//    for (int i = 0; i < MyData.size(); i++) {
//        sse += mindtc[i];
//    }
//    cout << "SSE : " << sse ;
//    cout << endl;
}


void POP::chkAEC(){

    vector <int> countID(centA.size());
//    cout <<" centA size : " << centA.size() << endl;
    for (int j = 0; j < MyData.size(); j++) {
        countID[MyData[j].c_id]++;           
//        cout << MyData[j].c_id << " ";
    } 

//    cout << endl << " CountID : ";
//    for (int i = 0; i < centA.size(); i++) {
//        cout << countID[i] << "  ";
//    }
//    cout << endl;

    for (int i = 0; i < centA.size(); i++) {
        if (countID[i] < 2 ) {
            reinitial(MyData,centA);
            break;
        }
    }
//    cout << endl;

//    for (int j = 0; j < MyData.size(); j++) {
//        cout << MyData[j].c_id << " ";
//    } 
//
//    cout << endl;
 

//    cout <<" centA size : " << centA.size() << endl;

//    cout << endl;
}



void POP::genFit(){
//    for (int j = 0; j < MyData.size(); j++) {
//        cout << MyData[j].c_id << " ";
//    } 
//
    cout << endl;

    cout <<" TEST centA size : " << centA.size() << "    ,  ";
    // ------------- CS Measure --------------------------
    // CS Measure 之分母 ＝ min_all + eps
    double intra_cent[centA.size()][centA.size()];
    for (int i = 0; i < centA.size(); i++) {
            for (int j = 0; j < centA.size(); j++) {
                intra_cent[i][j] = pow((
                    pow((centA[i].x - centA[j].x),2)+
                    pow((centA[i].y - centA[j].y),2)+
                    pow((centA[i].z - centA[j].z),2)+
                    pow((centA[i].u - centA[j].u),2)) ,0.5);
                if(intra_cent[i][j]==0)
                    intra_cent[i][j] = 1000;  //give a huge value
            }
    }

    
    //------------- Use For DB measure 之分母 ----------------- 
    double Minkowski = 0;                                       
    //cout << endl;                                              
    for (int i = 0; i < centA.size(); i++) {                  
            for (int j = 0; j < centA.size(); j++) {           
                //cout << setw(8) << intra_cent[i][j] << " ";      
                if(intra_cent[i][j] != 1000 ){                  
                    Minkowski += intra_cent[i][j];
                }

            }                                                        
            //cout << endl;
    }
    //cout << endl;
    //cout << " M_ij = " << Minkowski << "   ,    ";
    //------------- Use For DB measure 之分母 -----------------



    double min = 0;
    double min_all = 0;
    double eps = 0.0002;

    for (int i = 0; i < centA.size(); i++) {
        min = intra_cent[i][0];
            for (int j = 0; j < centA.size(); j++) {
                if (min > intra_cent[i][j]) {
                    min = intra_cent[i][j];
                }
            }
            min_all += min;
    }

//    cout << " min_all : " << min_all;
//    cout << endl;
    // CS Measure 之分母 ＝ min_all + eps
//    vector <int> countID(centA.size());
//    for (int j = 0; j < MyData.size(); j++) {
//        countID[MyData[j].c_id]++;           
//        cout << MyData[j].c_id << " ";
//    } 
//
//
//    cout << endl << " CountID : ";
//    for (int i = 0; i < centA.size(); i++) {
//        cout << countID[i] << "  ";
//    }
//    cout << endl;

    // CS Measure 之分子 ＝ 在一群內對於每個點找和其他點之max distance
    // 所有在這群內的max加起來乘上1/N
    
    double MaxDist[MyData.size()][2]; 
    double dist = 0;
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < 2; j++) {
            MaxDist[i][j] = 0;
        }
    } //initial MaxDist array to 0
    // An array put c_id and maxdist for each point 
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < MyData.size(); j++) {
            if ((i!=j) && (MyData[i].c_id == MyData[j].c_id )) {
                dist = pow((
                    pow((MyData[i].x - MyData[j].x),2)+
                    pow((MyData[i].y - MyData[j].y),2)+
                    pow((MyData[i].z - MyData[j].z),2)+
                    pow((MyData[i].u - MyData[j].u),2)) ,0.5);

                MaxDist[i][0] = MyData[i].c_id;

                if(MaxDist[i][1] < dist)
                    MaxDist[i][1] = dist;
            }
        }
    }

    //------------- Use For DI measure 之分母 -----------------
    double Gmax = 0;
    for (int i = 0; i < MyData.size(); i++) {
        if(Gmax < MaxDist[i][1])
            Gmax = MaxDist[i][1];
    }

//    cout << " The Global Max in one cluster : " << Gmax << "  ,   ";
    //------------- Use For DI measure 之分母 -----------------
    //------------- Use For DI measure 之分子 -----------------

    double minDist[MyData.size()][2];
    dist = 0;
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < 2; j++) {
            minDist[i][j] = 100;//find min value initial with large value 
        }
    }
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < MyData.size(); j++) {
            if ((i!=j) && (MyData[i].c_id != MyData[j].c_id)) {
                dist = pow((
                    pow((MyData[i].x - MyData[j].x),2) +
                    pow((MyData[i].y - MyData[j].y),2) +
                    pow((MyData[i].z - MyData[j].z),2) +
                    pow((MyData[i].u - MyData[j].u),2)) , 0.5);

                minDist[i][0] = MyData[i].c_id;

                if (minDist[i][1] > dist) 
                    minDist[i][1] = dist;
                
            }
        }
    }
    double Gmin = 10000; //find min value initial with large value 
    for (int i = 0; i < MyData.size(); i++) {
        if (Gmin > minDist[i][1]) {
            Gmin = minDist[i][1];
        }
    }
//    cout << " The Global min between cluster : " << Gmin << endl;
//    for (int i = 0; i < MyData.size(); i++) {
//        for (int j = 0; j < 2; j++) {
//            cout << minDist[i][j]  << " ";
//        }
//        
//        cout << endl; 
//    } 
//    cout << endl; 

    //------------- Use For DI measure 之分子 -----------------
    //------------- Use For Dunn's index ----------------------

    double Fit_DI_Measure = Gmin/Gmax;
    cout << " Fitness (DI) : " << Fit_DI_Measure << "   ,  ";


    //------------- Use For Dunn's index ----------------------



//    cout << " MaxDist = " << endl;
//    for (int i = 0; i < MyData.size(); i++) {
//        for (int j = 0; j < 2; j++) {
//            cout << MaxDist[i][j]  << " ";
//        }
//        
//        cout << endl; 
//    } 
//    cout << endl; 

    vector<int> countIDk(centA.size());
    vector<double> MaxDistAll(centA.size());
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < centA.size(); j++) {
            if (MaxDist[i][0] == j) {
                countIDk[j]++;
                MaxDistAll[j] += MaxDist[i][1];
            }
        }
    }


    //------------- Use For DB measure 之分子 -----------------
    vector<double> S(centA.size());
    for (int i = 0; i < MyData.size(); i++) {
        for (int j = 0; j < centA.size(); j++) {
            if (MyData[i].c_id == j) {
                dist = 
                    pow((MyData[i].x - centA[j].x),2) +
                    pow((MyData[i].y - centA[j].y),2) +
                    pow((MyData[i].z - centA[j].z),2) +
                    pow((MyData[i].u - centA[j].u),2) ;

                S[j] += dist;
            }
        }
    }

    double R = 0;
    for (int i = 0; i < centA.size(); i++) {
        R += S[i]/countIDk[i];
    }
 

    //cout << " Fitness (DB) : " << R/Minkowski << "  ,  ";
    



    //------------- Use For DB measure 之分子 -----------------


//    cout << endl << " CountID : ";
//    for (int i = 0; i < centA.size(); i++) {
//        cout << countIDk[i] << "  ";
//    }
//    cout << endl;
// 
//
//    cout << endl << " MaxDistAll : ";
//    for (int i = 0; i < centA.size(); i++) {
//        cout << MaxDistAll[i] << " ";
//    }
//    cout << endl;

    double element = 0; //分子
    for (int i = 0; i < centA.size(); i++) {
        element += MaxDistAll[i]/countIDk[i];
    }
    
    Fit_CS_Measure = 0;
    Fit_CS_Measure = 1/((element/min_all)+eps);

    double Fit_DB_Measure = 1/((R/Minkowski)+eps);

    cout << " Fitness (DB) : " << Fit_DB_Measure << "  ,  ";
    cout << "Fitness (CS) : " << Fit_CS_Measure << endl;


}

double POP::getFit(){
    return Fit_CS_Measure;
}


void POP::setgN(int gn){
    gN = gn;
}

POP operator+(const POP &op1, const POP &op2){
    POP temp(op1.cNum);

    temp.cent[op1.gN].x = op1.cent[op1.gN].x + op2.cent[op1.gN].x;
    temp.cent[op1.gN].y = op1.cent[op1.gN].y + op2.cent[op1.gN].y;
    temp.cent[op1.gN].z = op1.cent[op1.gN].z + op2.cent[op1.gN].z;
    temp.cent[op1.gN].u = op1.cent[op1.gN].u + op2.cent[op1.gN].u;
    temp.cent[op1.gN].t = op1.cent[op1.gN].t + op2.cent[op1.gN].t;
    
    temp.gN = op1.gN;

    return temp;
}       


POP operator-(const POP &op1, const POP &op2){
    POP temp(op1.cNum);
    
    // check fabs is needed or not???????????
    temp.cent[op1.gN].x = fabs(op1.cent[op1.gN].x - op2.cent[op1.gN].x);
    temp.cent[op1.gN].y = fabs(op1.cent[op1.gN].y - op2.cent[op1.gN].y);
    temp.cent[op1.gN].z = fabs(op1.cent[op1.gN].z - op2.cent[op1.gN].z);
    temp.cent[op1.gN].u = fabs(op1.cent[op1.gN].u - op2.cent[op1.gN].u);
    temp.cent[op1.gN].t = op1.cent[op1.gN].t - op2.cent[op1.gN].t;
    
    temp.gN = op1.gN;

    return temp;
   
}

POP operator*(double F, const POP & op2){
    POP temp(op2.cNum);

    temp.cent[op2.gN].x = F*op2.cent[op2.gN].x;
    temp.cent[op2.gN].y = F*op2.cent[op2.gN].y;
    temp.cent[op2.gN].z = F*op2.cent[op2.gN].z;
    temp.cent[op2.gN].u = F*op2.cent[op2.gN].u;
    temp.cent[op2.gN].t = F*op2.cent[op2.gN].t;
    
    temp.gN = op2.gN;

    return temp;
    
}

POP operator%=(POP &op1, const POP &op2){
    op1.cent[op1.gN].x = op2.cent[op2.gN].x;
    op1.cent[op1.gN].y = op2.cent[op2.gN].y;
    op1.cent[op1.gN].z = op2.cent[op2.gN].z;
    op1.cent[op1.gN].u = op2.cent[op2.gN].u;

    if(op2.cent[op2.gN].t < 0)
        op1.cent[op1.gN].t = 0;
    else if(op2.cent[op2.gN].t > 1)
        op1.cent[op2.gN].t = 1;
    else
        op1.cent[op1.gN].t = op2.cent[op2.gN].t;

    return op1;

}

POP& POP::operator=(const POP& op1){
    for (int i = 0; i < cNum; i++) {
        this->cent[i].x = op1.cent[i].x;
        this->cent[i].y = op1.cent[i].y;
        this->cent[i].z = op1.cent[i].z;
        this->cent[i].u = op1.cent[i].u;
        this->cent[i].t = op1.cent[i].t;
    }
    return *this;
}


void POP::Output(){
    for (int i = 0; i < MyData.size(); i++) {
        if(i%50 == 0)
            cout << "============== Cluster ==============" << endl;
        cout << setw(3) << MyData[i].x << " " << setw(3) << MyData[i].y << " "
             << setw(3) << MyData[i].z << " " << setw(3) << MyData[i].u << " "
             << setw(3) << MyData[i].c_id << endl;
    }
}
