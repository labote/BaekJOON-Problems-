//
//  Problem2156.cpp
//  Problems
//
//  Created by 홍민성 on 09/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int dp[MAX];
int wine[MAX];

int answer(int num){
//    if(num==1) dp[1]=wine[1];
//    if(num==2) dp[2]=wine[1]+wine[2];
//
    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];

    for(int i=3;i<=num;i++){
        dp[i]=max({wine[i]+dp[i-2], wine[i]+wine[i-1]+dp[i-3],dp[i-1]});
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
    cout << answer(num) << endl;
}
