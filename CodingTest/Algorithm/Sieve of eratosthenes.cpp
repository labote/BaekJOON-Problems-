//
//  Sieve of eratosthenes.cpp
//  Problems
//
//  Created by 홍민성 on 26/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//


//소수를 찾는 방법 중 하나, 에라토스테네스의 체

#include <iostream>
#define MAX 100001

using namespace std;

int arry[MAX];

void eratosthenes(int n){
    for(int i=2;i<=n;i++){
        arry[i]=i;
    }
    
    for(int i=2;i<=n;i++){
        if(arry[i]==0) continue;
        for(int j=i+i;j<=n;j=j+i){
            arry[j]=0;
        }
    }
    
    for(int i=2;i<=n;i++){
        if(arry[i]!=0) {
            cout << arry[i] << " ";
        }
    }
}

int main(){
    int num;
    cin >> num;
    
    eratosthenes(num);
}
