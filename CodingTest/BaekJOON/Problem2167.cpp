//
//  Problem2167.cpp
//  Problems
//
//  Created by 홍민성 on 2020/02/02.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 301
using namespace std;

int N,M,K;
int dp[MAX][MAX];
int num[MAX][MAX];
vector<int> ans;

void DP(int i, int j, int x, int y){
    for(int m=i;m<=x;m++){
        for(int n=j;n<=y;n++){
            dp[x][y]+=num[m][n];
        }
    }
    ans.push_back(dp[x][y]);
    dp[x][y]=0;
}

int main(){
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> num[i][j];
        }
    }
    
    cin >> K;
    
    for(int t=0;t<K;t++){
        int i,j,x,y;
        cin >> i >> j >> x >> y;
        DP(i,j,x,y);
    }
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
