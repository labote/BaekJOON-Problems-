//
//  Problem2644.cpp
//  Problems
//
//  Created by 홍민성 on 12/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define visited true
#define Non_visited false

using namespace std;

typedef pair<int,int> pir;
vector<vector<int>> vec;
vector<int> v;
vector<bool> check;
vector<int> cnt;

void bfs(int a, int b){
    queue<pir> q;
    q.push(pir(a,b));
    check[a]=visited;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
//        if(check[x]==visited) continue;
//        check[x]=visited;
//
        for(int i=0;i<vec[x].size();i++){
            int z=vec[x][i];
            if(z==y){
                cnt[z]=cnt[x]+1;
                return;
            }
            if(check[z]!=visited){
                check[z]=visited;
                q.push(pir(z,y));
                cnt[z]=cnt[x]+1;
            }
        }
    }
}

int main(){
    int num;
    cin >> num;
    
    v=vector<int> (num+1,0);
    check=vector<bool> (num+1,0);
    cnt=vector<int> (num+1,0);
    
    for(int i=0;i<=num;i++){
        vec.push_back(v);
    }
    
    int a,b,x,y;
    cin >> a >> b;
    
    int m;
    cin >> m;
    
    for(int i=0;i<m;i++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    bfs(a,b);

    if(cnt[b]==0){
        cout << -1 << endl;
    }else
        cout << cnt[b] << endl;
}
