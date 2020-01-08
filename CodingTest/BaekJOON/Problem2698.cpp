//
//  Problem2698.cpp
//  Problems
//
//  Created by 홍민성 on 24/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

typedef pair<int,int> pir;
queue<pir> q;
int val[MAX][MAX][2];

int dp(int n,int k){
    int ans;
    
    //미리 저장된 값이 있으면 바로 출력
    if(val[n][k][0]!=0 && val[n][k][1]!=0){
        return ans=val[n][k][0]+val[n][k][1];
    }
    
    //초기값 선언
    val[1][0][0]=1;
    val[1][0][1]=1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                val[i][j][1]=val[i-1][j][0];
            }
            else{
                val[i][j][1]=val[i-1][j][0]+val[i-1][j-1][1];
            }
            val[i][j][0]=val[i-1][j][0]+val[i-1][j][1];
        }
    }
    ans=val[n][k][0]+val[n][k][1];
    
    return ans;
}

int main(){
    int num;
    cin >> num;
    
    while(num--){
        int M,N;
        cin >> M >> N;
        q.push(pir(M,N));
    }
    
    while(!q.empty()){
        int n = q.front().first;
        int k = q.front().second;
        q.pop();
        
        cout << dp(n,k) << endl;
    }
    
    
}
