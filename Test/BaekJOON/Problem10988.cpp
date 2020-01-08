//
//  Problem10988.cpp
//  Problems
//
//  Created by 홍민성 on 02/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 100001*2
using namespace std;

string tmp;
int A[MAX];

void Manacher(string S, long int num){
    int r=0;
    int p=0;
    for(int i=0;i<num;i++){
        if(i<=r) A[i]=min(A[2*p-i],r-i);
        else A[i]=0;
        while(i-A[i]-1>=0 && i+A[i]+1<num && S[i-A[i]-1]==S[i+A[i]+1])
            A[i]++;
        if(r<i+A[i]){
            r=i+A[i];
            p=i;
        }
    }
}

int main(){
    string str;
    cin >> str;
    
    long int size=str.size();
    
    for(int i=0;i<=size;i++){
        tmp+='#';
        tmp+=str[i];
    }
    
    tmp+='#';
    
    size=tmp.size();
    
    Manacher(tmp, size);
    
    int ans=-1;
    for(int i=0;i<size;i++){
        ans=max(ans,A[i]);
    }
    if(ans==str.size()){
        cout << "1" << endl;
    }else
        cout << "0" << endl;
//    for(int i=0;i<size;i++){
//        cout << A[i] << " ";
//    }
}
