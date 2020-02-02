//
//  Problem1699.cpp
//  Problems
//
//  Created by 홍민성 on 2020/01/30.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int N;
int dp[MAX];

void DP(){
    
    dp[1]=1;
    
    for(int i=2;i<=N;i++){
        int j=1;
        dp[i]=1+dp[i-j*j];
        for(int j=2;j*j<=i;j++){
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
}

int main(){
    cin >> N;
    
    DP();
    
    cout << dp[N] << endl;
}
