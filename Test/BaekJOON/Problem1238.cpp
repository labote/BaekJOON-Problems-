//
//  Problem1238.cpp
//  Problems
//
//  Created by 홍민성 on 11/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<int>> vec;
vector<int> v;

void floydWarshall(int N){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(vec[i][k]+vec[k][j]<vec[i][j]){
                    vec[i][j]=vec[i][k]+vec[k][j];
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M,X;
    cin >> N >> M >> X;
    
    int a,b,c;
    
    v=vector<int> (N,0);

//    v.resize(N); 대신 초기값을 넣어주어야한다.
    
    for(int i=0;i<N;i++){
        vec.push_back(v);
    }
    
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        if(vec[a-1][b-1]!=0){
            c=min(vec[a-1][b-1],c);
        }
        vec[a-1][b-1]=c;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j && vec[i][j]==0){
                vec[i][j]=INF;
            }
        }
    }
    
    floydWarshall(N);

    int ans=-1;
    
    for(int i=0;i<N;i++){
        if(vec[i][X-1]+vec[X-1][i]>ans){
            ans=vec[i][X-1]+vec[X-1][i];
        }
    }
    
    cout << ans << endl;
}
