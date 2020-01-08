//
//  Problem7569.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cmath>
#define visited true
#define Non_visited false
#define MAX 101

using namespace std;

int xx[6]={1,0,0,-1,0,0};
int yy[6]={0,1,0,0,-1,0};
int zz[6]={0,0,1,0,0,-1};
int Check[MAX][MAX][MAX];
int BOX[MAX][MAX][MAX];
int cnt;
queue<pair<int,int>> xy;
queue<int> h;

int bfs(int M, int N, int H){
    
    while(!xy.empty() && !h.empty()){
        
        long int size = xy.size();
        
        while(size--){
            int x=xy.front().first;
            int y=xy.front().second;
            int z=h.front();
            
            xy.pop();
            h.pop();
            
            for(int i=0;i<6;i++){
                int nx=x+xx[i];
                int ny=y+yy[i];
                int nz=z+zz[i];
                
                if(nx<0 || ny<0 || nz<0 || nx>=M || ny>=N || nz>=H) continue;
                if(BOX[nx][ny][nz]==-1 || BOX[nx][ny][nz]==1) continue;
                
                xy.push(make_pair(nx,ny));
                h.push(nz);
                BOX[nx][ny][nz]=1;
                Check[nx][ny][nz]=Check[x][y][z]+1;
            }
        }
    }
    
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(BOX[j][i][k]==0){
                    return -1;
                }
                cnt=max(cnt,Check[j][i][k]);
            }
        }
    }

    
    return cnt;
}

using namespace std;

int main(){
    int M,N,H;
    cin >> M >> N >> H;
    
    int height = H;
    while(height--){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int num;
                cin >> num;
                BOX[j][i][height]=num;
                if(BOX[j][i][height]==1){
                    xy.push(make_pair(j,i));
                    h.push(height);
                }
            }
        }
    }
    
    cout << bfs(M,N,H) << endl;

}

