//
//  Problem11053.cpp
//  Problems
//
//  Created by 홍민성 on 09/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 1001

using namespace std;

int N;
int A[MAX];
int dp[MAX];
int ans;

void DP(){
    for(int i=0;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    
    cout << ans << endl;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    DP();
}
