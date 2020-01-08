//
//  Problem1309.cpp
//  Problems
//
//  Created by 홍민성 on 28/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 100001
#define mod 9901

using namespace std;

int dp[MAX][3];

int Zoo(int num){
    
    int ans=0;
    
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    
    for(int i=2;i<=num;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%mod;
    }
    
    ans = (dp[num][0]+dp[num][1]+dp[num][2])%mod;
    
    return ans;
}

int main(){
    int num;
    cin >> num;
    
    cout << Zoo(num) << endl;
}
