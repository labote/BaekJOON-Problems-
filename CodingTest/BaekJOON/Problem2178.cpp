//
//  Problem2178.cpp
//  Problems
//
//  Created by 홍민성 on 23/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int iArr[MAX][MAX];
int cnt[MAX][MAX];
int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};

void bfs(int Xstart, int Ystart, int M, int N){
    queue<pair<int,int>> q;
    //q.push(pair<int,int>(Xstart,Ystart));
    q.push(make_pair(Xstart,Ystart));
    cnt[Xstart][Ystart] = 1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+xx[i];
            int ny=y+yy[i];
            
            if(0<=nx && 0<=ny && nx<M && ny<N && iArr[nx][ny] == 1 && cnt[nx][ny] == 0){
                cnt[nx][ny]=cnt[x][y]+1;
                q.push(pair<int,int>(nx,ny));
            }
        }
    }
}

int main(){
    int M,N;
    cin>>M>>N;
    
    for(int i=0;i<M;i++){
        string number;
        cin >> number;
        for(int j=0;j<N;j++){
            if(number[j]=='1'){
                iArr[i][j]=1;
            }
        }
    }
    
    bfs(0,0,M,N);
    
    cout << cnt[M-1][N-1] << endl;
}

