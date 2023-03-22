//CS211
//Tezin dhargyal
//Assignment 7
//Describtion: Stable marriage problem using one dimensional array representation.
//Date:Oct-25- 2020

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;




  
bool ok(int q[], int col){

    //mp = man's preference; wp = women's preference
    //mp[i][j] gives man i's ranking of woman j
    //lower value implies higher ranking
    int mp[3][3] = {{0,2,1},   //man 0 likes woman 0 the most and woman 1 the least.
                    {0,2,1},
                    {1,2,0}};

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    //cm = a currently assigned man
    //cw = a currently assigned woman
    //nm = new man
    //nw = new woman
    //nm and nw are the proposed pair to add to the match

    int cm, cw, nm, nw;

   
    for (int i = 0; i < col; i++){
        cm = i;
        cw = q[i];
        nm = col;
        nw = q[col];
        if(nw==cw)return false;// check to see if a newwomen is already assogned to some men.
    }
      

    for (int i = 0; i < col; i++){
        
        cm = i;
        cw = q[i];//women assigned to men i
        nm = col;
        nw = q[col];
        //   a. if the current man prefers the new woman to his partner and
        //   b. if the new woman prefers the current man to her partner, reject
        if(mp[cm][cw]>mp[cm][nw]&&wp[nw][cm]>wp[nw][nw]) return false;

        //   c. if the new man prefers the current woman to his partner and
        //   d. if the current woman prefers the new man to her partner, reject
        if(mp[nm][cw]>mp[nm][nw]&&wp[cw][nm]>wp[cw][cm]) return false;
        
    }

    return true; //since the pair nm & nw do not introduce an instability
}


void backtrack(int &col){// viod doesnt have to return that why it isused
    col--;// backtrcking and recursion is used
    if(col==-1) exit(1);
    
};

void printOutput(int q[]){//printouts the list
    // printout function related to women
    static int count= 0;// static If it's a variable in a function, it can't be accessed from outside of the function, just like any other local variable. (this is the local they mentioned)
    
    cout << "\n" <<"Group: " << ++count << endl<< endl;
    cout << "Man   Women" << endl<< endl;
    for(int i = 0; i <3; i++){
        cout <<" "<< i <<"    "<< q[i] << endl;
        
    }
    cout << endl << endl;
};


//

int main(){
    int q[3]; q[0]=0;
    int c=0;
    bool from_backtrack=false;
    
    cout <<"The Group of stable  marriages are as follows:" << endl;

    while(true){
        while(c<3){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<3){
                q[c]++;
                if(q[c]==3){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        printOutput(q);
        backtrack(c);
        from_backtrack=true;
    }
    return 0;
}
