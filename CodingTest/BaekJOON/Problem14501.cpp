//
//  Problem14501.cpp
//  Problems
//
//  Created by 홍민성 on 08/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 16

using namespace std;

int T[MAX];
int P[MAX];
int dp[MAX];
int num;

int DP(int day){
    if(day>num) return 0;
    if(dp[day]>0) return dp[day];
    if(day+T[day]<=num+1) dp[day]=max(dp[day],DP(day+T[day])+P[day]);
    if(day<=num) dp[day]=max(dp[day],DP(day+1));
    return dp[day];
}

int main(){
    cin >> num;
    
    for(int i=1;i<=num;i++){
        cin >> T[i] >> P[i];
    }
    
    cout << DP(1) << endl;
}
