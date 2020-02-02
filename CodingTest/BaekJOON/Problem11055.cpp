//
//  Problem11055.cpp
//  Problems
//
//  Created by 홍민성 on 2020/02/02.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;

int N;
int dp[MAX];
int sum[MAX];
int ans;

void DP(){
    for(int i=0;i<N;i++){
        sum[i]=dp[i];
        for(int j=0;j<i;j++){
            if(dp[i]>dp[j]){
                sum[i]=max(sum[i],dp[i]+sum[j]);
            }
        }
        ans=max(ans,sum[i]);
    }
    cout << ans << endl;
}

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> dp[i];
    }
    
    DP();
}
