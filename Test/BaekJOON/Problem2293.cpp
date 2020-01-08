//
//  Problem2293.cpp
//  Problems
//
//  Created by 홍민성 on 19/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

vector<int> coin;
int dp[MAX];

int DP(int n, int k){
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j-coin[i]<0){
                dp[j]+=0;
            }
            else
                dp[j]+=dp[j-coin[i]];
        }
    }
    return dp[k];
}

int main(){
    int n,k,num;
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        cin >> num;
        coin.push_back(num);
    }
    
    cout << DP(n,k) << endl;
}
