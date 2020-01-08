//
//  Problem9372.cpp
//  Problems
//
//  Created by 홍민성 on 18/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define visited true
#define Non_visited false
#define MAX 10001

using namespace std;

vector<int> vec[MAX];
bool check[MAX];
int cnt;
queue<int> ans;

void bfs(int start){
    queue<int> q;
    q.push(start);

    check[start]=visited;
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<vec[x].size();i++){
            int y=vec[x][i];
            if(check[y]==Non_visited){
                cnt++;
                check[y]=visited;
                q.push(y);
            }
        }
    }
}

int main(){
    int num;
    cin >> num;
    
    while(num--){
        int N,M;
        cin >> N >> M;
        
        for(int i=0;i<M;i++){
            int x,y;
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        bfs(1);
        ans.push(cnt);
        cnt=0;
        memset(vec,0,sizeof(vec));
        memset(check,Non_visited,sizeof(check));
    }
    while(!ans.empty()){
        int x=ans.front();
        ans.pop();
        cout << x << endl;
    }
}
