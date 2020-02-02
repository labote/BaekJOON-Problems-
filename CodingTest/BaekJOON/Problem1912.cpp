//
//  Problem1912.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int dp[MAX];
int sum[MAX];
int ans=-1001;
int N;

void DP(){
    int k=0;
    for(int i=0;i<N;i++){
        for(int j=k;j<=i;j++){
            sum[i]+=dp[j];
            if(sum[i]<0){
                k=i+1;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> dp[i];
    }

    DP();

    for(int i=0;i<N;i++){
        ans=max(ans,sum[i]);
    }
    cout << ans << endl;
}

