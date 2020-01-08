//
//  Problem13235.cpp
//  Problems
//
//  Created by 홍민성 on 02/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 100
using namespace std;

int A[MAX];
string tmp;

void manacher(string S, long int num){
    int r=0,p=0;
    for(int i=0;i<num;i++){
        
        if(i<=r){
            A[i]=min(r-i,A[2*p-i]);
        }
        else A[i]=0;
        while(i-A[i]-1>=0 && i+A[i]+1<num && S[i-A[i]-1]==S[i+A[i]+1]){
            A[i]++;
        }
        if(r<i+A[i]){
            r=i+A[i];
            p=i;
        }
    }
}

int main(){
    string str;
    cin >> str;
    
    long int strSize=str.size();
    
    for(int i=0;i<strSize;i++){
        tmp+='#';
        tmp+=str[i];
    }
    tmp+='#';
    
    long int tmpSize=tmp.size();
    
    manacher(tmp,tmpSize);
    
    int ans=0;
    for(int i=0;i<tmpSize;i++){
        ans=max(ans,A[i]);
    }
    if(ans==strSize){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}
