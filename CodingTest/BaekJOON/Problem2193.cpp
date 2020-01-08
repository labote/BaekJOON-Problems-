//
//  Problem2193.cpp
//  Problems
//
//  Created by 홍민성 on 24/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 91

using namespace std;

long long dp[MAX][3];
int num;

void DP(){
    
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    
    for(int i=2;i<=num;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0];
    }
    
    long long ans=0;
    ans=dp[num][0]+dp[num][1];
    
    cout << ans << endl;
}

int main(){
    cin >> num;
    
    DP();
}
