//
//  KakaoTest3.cpp
//  Problems
//
//  Created by 홍민성 on 07/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int dp[MAX];
int wine[MAX];

int Wine(int num){
    if(num==1){
        dp[num]=wine[num];
    }
    if(num==2){
        dp[num]=wine[num]+wine[num-1];
    }
    
    for(int i=3;i<=num;i++){
        dp[num]=max(dp[num-2]+wine[num],dp[num-3]+wine[num]+wine[num-1]);
        dp[num]=max(dp[num],dp[num-1]);
    }
    
    return dp[num];
}

int main(){
    int num;
    cin >> num;
    
    for(int i=1;i<=num;i++){
        int M;
        cin >> M;
        wine[i]=M;
    }
    cout << Wine(num) << endl;
}

