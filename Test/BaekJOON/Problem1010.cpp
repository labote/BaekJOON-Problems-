//
//  Problem1010.cpp
//  Problems
//
//  Created by 홍민성 on 18/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 31

using namespace std;

queue<long long> ans;

int cache[MAX][MAX];

void dp(int M, int N){
    
    for(int j=0;j<N;j++){
        cache[0][j]=1;
    }
    
    for(int i=1;i<=M;i++){
        for(int j=i;j<=N;j++){
            for(int k=i-1;k<=j-1;k++){
                cache[i][j]+=cache[i-1][k];
            }
        }
    }
    ans.push(cache[M][N]);
    memset(cache,0,sizeof(cache));
}

int main(){
    int num;
    cin >> num;
    
    while(num--){
        int M,N;
        cin >> M >> N;
        
        dp(M,N);
    }
    
    while(!ans.empty()){
        long long key=ans.front();
        ans.pop();
        cout << key << endl;
    }
}
