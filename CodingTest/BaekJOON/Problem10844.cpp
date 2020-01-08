//
//  Problem10844.cpp
//  Problems
//
//  Created by 홍민성 on 04/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 101
#define mod 1000000000
using namespace std;

long long dp[MAX][10];

long long stair(int num){
    int sum=0;
    
    for(int j=1;j<=9;j++){
        dp[1][j]=1;
    }
    
    for(int i=2;i<=num;i++){
        dp[i][0]=dp[i-1][1]%mod;
        dp[i][9]=dp[i-1][8]%mod;
        for(int j=1;j<=8;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]%mod;
        }
    }
    
    for(int i=0;i<=9;i++){
        sum=(sum+dp[num][i])%mod;
    }
    
    return sum%mod;
}
int main(){
    int num;
    cin >> num;
    cout << stair(num) << endl;
}
