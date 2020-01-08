//
//  Problem2667.cpp
//  Problems
//
//  Created by 홍민성 on 23/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 26
#define visited true
#define Non_visited false

using namespace std;

typedef pair<int,int> pir;

vector<string> vec;
vector<int> cnt;
bool check[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int ans;

void bfs(int N, int firstX, int firstY){
    queue<pir> q;
    q.push(pir(firstX,firstY));
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(check[x][y]==visited) continue;
        check[x][y]=visited;
        ans++;
        
        for(int i=0;i<4;i++){
            int nx=x+xx[i];
            int ny=y+yy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N || vec[nx][ny]=='0') continue;
            q.push(pir(nx,ny));
        }
    }
    cnt.push_back(ans);
    ans=0;
}

int main(){
    string str;
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin>>str;
        vec.push_back(str);
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vec[i][j]=='1' && check[i][j]!=visited){
                bfs(N,i,j);
            }
        }
    }
    
    long int size=cnt.size();
    
    sort(cnt.begin(),cnt.end());
    
    cout << size << endl;
    
    for(int i=0; i<size; i++){
        cout << cnt[i] << endl;
    }
    
}
