#include "DE.h"

double randf(){
    return rand()/ double(RAND_MAX);
}
    
void DE::Init(vector<DATA> MyData){

   // cout << "x: " << MyData[0].x << endl;
    for (int i = 0; i < pSize; i++) {        
        population[i].Input(MyData);
        population[i].genCent();
    }
    
}

void DE::Assign(){
    for (int i = 0; i < pSize; i++) {
        population[i].genAssign();
    }
//    population[0].genAssign();
//    population[1].genAssign();
//    population[2].genAssign(MyData);
//    population[3].genAssign(MyData);
}

void DE::AEC(){
    for (int i = 0; i < pSize; i++) {
        population[i].chkAEC();
    }
//
//    population[0].chkAEC();
//    population[1].chkAEC();
}


void DE::Mutant(int iter){
    

        POP newPop(cNum);
        double CR_max = 1;
        double CR_min = 0.5;

        //cout << " =========== Mutation Fitness =================" << endl;
    for (int k = 0; k < pSize; k++) {
            
//        int a = rand()%pSize;
//        int b = rand()%pSize;
//        int c = rand()%pSize;
//        while (k==a) 
//            a = rand()%pSize;
//        while (b==a || b==k) 
//            b = rand()%pSize;
//        while (c==a || c==b || c==k)
//            c = rand()%pSize;

        int a, b, c;
        do{
             a = rand()%pSize;
             b = rand()%pSize;
             c = rand()%pSize;
        }while(a==k || b==k || c==k || a==b || b==c || c==a);

        //POP newPop(cNum);
        double F = 0.5*(1+randf());
        //double CR_max = 1;
        //double CR_min = 0.5;
        double CR = CR_min + (CR_max - CR_min)*(MaxIter - iter)/MaxIter;

        //cout << " F : "<< F << " CR : " << CR << endl;

        for (int i = 0; i < cNum; i++) {
            population[a].setgN(i);
            population[b].setgN(i);
            population[c].setgN(i);
            population[k].setgN(i);
            newPop.setgN(i);

            if(randf() < CR){
                newPop %= (population[a] + (F*(population[b] - population[c])));
            }
            else
                newPop %= population[k];
            
            //newPop.getCentV(i);
        }
        //newPop.Input(population[a].getData());
        ////newPop.genCentA();
        //newPop.genAssign();
   
        //newPop.chkAEC();
        //newPop.genFit();

//        for (int i = 0; i < cNum; i++) {
//            population[0].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[1].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[2].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[3].getCentV(i);
//        }
//        cout << newPop.getFit() << endl;
//        cout << population[0].getFit() << endl;
//        cout << population[1].getFit() << endl;
//        cout << population[2].getFit() << endl;
//        cout << population[3].getFit() << endl;
        

        //for (int i = 0; i < pSize; i++) {
            for (int j = 0; j < cNum; j++) {
                mutation[k].setgN(j);
                newPop.setgN(j);
                mutation[k] %= newPop;
            }
        //}
    }
//        for (int i = 0; i < cNum; i++) {
//            population[0].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[1].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[2].getCentV(i);
//        }
//        for (int i = 0; i < cNum; i++) {
//            population[3].getCentV(i);
//        }
    cout << " ================= Mutation =======================" << endl;
        for (int i = 0; i < cNum; i++) {
            mutation[0].getCentV(i);
        }
        for (int i = 0; i < cNum; i++) {
            mutation[1].getCentV(i);
        }
        for (int i = 0; i < cNum; i++) {
            mutation[2].getCentV(i);
        }
        for (int i = 0; i < cNum; i++) {
            mutation[3].getCentV(i);
        }

        for (int g = 0; g < pSize; g++) {
            
        
        mutation[g].Input(population[0].getData());
        mutation[g].genAssign();
   
        mutation[g].chkAEC();


        mutation[g].genFit();
        }
}




void DE::Crossover(){
}


void DE::Fit(){
    for (int i = 0; i < pSize; i++) {
        population[i].genFit();
    }
}


void DE::Select(){
    for (int i = 0; i < pSize; i++) {
          for (int j = 0; j < cNum; j++) {
              population[i].setgN(j);
              mutation[i].setgN(j);
              if(mutation[i].getFit() > population[i].getFit())
                  population[i] %= mutation[i];
          }
      }
    //mutation.clear();

}


void DE::Iteration(vector<DATA> MyData, int MaxIter){

    Init(MyData);

    int iter;
    for (int i = 0; i < MaxIter; i++) {
        iter = i+1;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~ " << iter << " ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        Assign();
        AEC();
        Fit();
        Mutant(iter);
        Select();
    }
    population[0].Output();
}




