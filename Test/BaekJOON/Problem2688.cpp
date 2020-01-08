//
//  Problem2688.cpp
//  Problems
//
//  Created by 홍민성 on 01/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <cstring>
#define MAX 1001

using namespace std;

int arr[MAX];
long long dp[MAX][10];

void DP(int M){
    
    //1일때 초기화값
    for(int j=0;j<10;j++){
        dp[1][j]=1;
    }
    
    //2이상 계산값
    for(int i=2;i<=M;i++){
        for(int j=0;j<10;j++){
            if(dp[i][j]>0) continue;
            for(int k=0;k<j+1;k++){
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    
    long long ans=0;
    
    for(int j=0;j<10;j++){
        ans+=dp[M][j];
    }
    cout << ans << endl;
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        int M;
        cin >> M;
        arr[i]=M;
    }
    
    for(int i=0;i<num;i++){
        DP(arr[i]);
        //memset(dp,0,sizeof(dp));
    }
    
}
