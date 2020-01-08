//
//  Problem2163.cpp
//  Problems
//
//  Created by 홍민성 on 17/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 301

using namespace std;

int dp[MAX][MAX];

int choco(int N, int M){
    dp[N][M]=N*M-1;
    return dp[N][M];
}

int main(){
    int N,M;
    cin>>N>>M;
    
    cout << choco(N,M) << endl;
}
