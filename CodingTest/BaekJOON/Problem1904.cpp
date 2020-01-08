//
//  Problem1904.cpp
//  Problems
//
//  Created by 홍민성 on 22/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 1000001
#define mod 15746

using namespace std;

int dp[MAX];

int tile(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(dp[n]!=0) return dp[n];
    
    return dp[n] = tile(n-1)%mod + tile(n-2)%mod;
}

int tile2(int n){
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]%mod + dp[i-2]%mod;
    }
    
    return dp[n]%mod;
}

int main(){
    int num;
    cin >> num;
    //cout << tile(num)%mod << endl;
    cout << tile2(num) << endl;
}
