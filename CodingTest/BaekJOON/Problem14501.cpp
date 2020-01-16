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
int num,result;

void DP(int day){
    if(day>num) return;
    if(day+T[day]<=num+1){
        dp[day+T[day]]+=P[day];
        DP(day+T[day]);
        result=max(result,dp[day+T[day]]);
    }
    if(day<num){
        DP(day+1);
        result=max(result,dp[day+1]);
    }
}

int main(){
    cin >> num;
    
    for(int i=1;i<=num;i++){
        cin >> T[i] >> P[i];
    }
    
    DP(1);
    
    cout << result << endl;
}
