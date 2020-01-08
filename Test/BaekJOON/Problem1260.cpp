//
//  Problem1260.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1001
#define visited true
#define Non_visited false

using namespace std;

vector<int> arry[MAX];
bool Check[MAX];

void dfs(int start){
    if(Check[start]) return;
    Check[start]=visited;
    cout << start << " ";
//    for(int i=0;i<arry[start].size();i++){
//        int y=arry[start][i];
    for(int y:arry[start]){
        dfs(y);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    Check[start]=visited;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout << x << " ";
//        for(int i=0;i<arry[x].size();i++){
//            int y=arry[x][i];
        for(int y:arry[x]){
            if(!Check[y]){
                q.push(y);
                Check[y]=visited;
            }
        }
    }
    cout << endl;
}

int main(){
    int N,M,V;
    cin >> N >> M >> V;
    
    for(int i=1; i<=M; i++){
        int x,y;
        cin>>x>>y;
        arry[x].push_back(y);
        arry[y].push_back(x);
    }
    
    for(int i=1; i<=N; i++){
        sort(arry[i].begin(),arry[i].end());
    }
    
    dfs(V);
    cout << endl;
    memset(Check,Non_visited,sizeof(Check));
    bfs(V);
}

// for문 콜론 사용법, 트리 만들때 왜 둘 다 넣어줘야하는가? 61-62줄
// DFS stack으로 구현해보기!
