//
//  Problem10769.cpp
//  Problems
//
//  Created by 홍민성 on 01/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int hCnt;
int sCnt;

vector<int> makePi(string expression){
    long int exSize=expression.size();
    vector<int> Pi(exSize,0);
    int j=0;
    for(int i=1;i<exSize;i++){
        while(j>0 && expression[i]!=expression[j]){
            j=Pi[j-1];
        }
        if(expression[i]==expression[j]){
            Pi[i]=++j;
        }
    }
    return Pi;
}

void HappyKMP(string str, string happy){
    vector<int> Pi=makePi(happy);
    long int strSize=str.size();
    long int happySize=happy.size();
    int j=0;
    for(int i=0;i<strSize;i++){
        while(j>0 && str[i]!=happy[j]){
            j=Pi[j-1];
        }
        if(str[i]==happy[j]){
            if(j==happySize-1){
                hCnt++;
                j=Pi[j];
            }
            else{
                j++;
            }
        }
    }
}
void SadKMP(string str, string sad){
    vector<int> Pi=makePi(sad);
    long int strSize=str.size();
    long int sadSize=sad.size();
    int j=0;
    for(int i=1;i<strSize;i++){
        while(j>0 && str[i]!=sad[j]){
            j=Pi[j-1];
        }
        if(str[i]==sad[j]){
            if(j==sadSize-1){
                sCnt++;
                j=Pi[j];
            }
            else{
                j++;
            }
        }
    }
}


int main(){
    string str;
    string happy=":-)";
    string sad=":-(";
    
    getline(cin,str);
    
    HappyKMP(str, happy);
    SadKMP(str, sad);
    
    if(sCnt>hCnt){
        cout << "sad" << endl;
    }else if(sCnt>0 && hCnt>0 && sCnt==hCnt){
        cout << "unsure" << endl;
    }else if(sCnt<hCnt){
        cout << "happy" << endl;
    }else cout << "none" << endl;
}
