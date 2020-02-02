//
//  Problem9465.cpp
//  Problems
//
//  Created by 홍민성 on 18/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int dp[MAX][2];
int N,num;
vector<int> ans;

void DP(){
    dp[1][0]=dp[0][1]+dp[1][0];
    dp[1][1]=dp[0][0]+dp[1][1];
    
    for(int i=2;i<num;i++){
        dp[i][0]=max(dp[i-1][1]+dp[i][0],dp[i-2][1]+dp[i][0]);
        dp[i][1]=max(dp[i-1][0]+dp[i][1],dp[i-2][0]+dp[i][1]);
    }
    int K;
    K=max(dp[num-1][0],dp[num-1][1]);
    ans.push_back(K);
}

int main(){
    cin >> N;
    
    while(N--){
        cin >> num;
        for(int i=0;i<2;i++){
            for(int j=0;j<num;j++){
                int score;
                cin >> score;
                dp[j][i]=score;
            }
        }
        DP();
    }
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
