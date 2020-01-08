//
//  Problem9084.cpp
//  Problems
//
//  Created by 홍민성 on 17/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001

using namespace std;

vector<int> vec;
vector<int> ans;
int dp[MAX];

void current(int M){
    dp[0]=1;
    for(int n : vec){
        for(int j=n;j<=M;j++){
            dp[j]+=dp[j-n];
        }
    }
    ans.push_back(dp[M]);
    memset(dp,0,sizeof(dp));
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int num;
        cin >>num;
        while(num--){
            int N;
            cin >> N;
            vec.push_back(N);
        }
        int M;
        cin >> M;
        current(M);
        while(!vec.empty()){
            vec.pop_back();
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
