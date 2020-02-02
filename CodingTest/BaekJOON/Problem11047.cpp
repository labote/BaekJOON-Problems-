//
//  Problem11047.cpp
//  Problems
//
//  Created by 홍민성 on 16/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 11

using namespace std;

int A[MAX];
int N,K;
int cnt;

int main(){
    cin >> N >> K;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    for(int i=N-1;i>=0;i--){
        if(A[i]==0) break;
        while(A[i]<=K){
            K-=A[i];
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
