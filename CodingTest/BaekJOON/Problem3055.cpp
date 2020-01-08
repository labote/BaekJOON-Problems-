//
//  Problem3055.cpp
//  Problems
//
//  Created by 홍민성 on 23/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 51

using namespace std;

typedef pair<int,int> pr;
char map[MAX][MAX];
int cnt[MAX][MAX];
bool Check[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
queue<pr> water;
queue<pr> hedgehog;

void bfs(int M, int N){

    while(!hedgehog.empty()){

        long int waterSize = water.size();
        long int hedgehogSize = hedgehog.size();

        while(waterSize--){
            int x = water.front().first;
            int y = water.front().second;
            water.pop();

            for(int i=0;i<4;i++){
                int nx=x+xx[i];
                int ny=y+yy[i];

                if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
                if(map[nx][ny]=='X' || map[nx][ny]=='D' || map[nx][ny]=='*') continue;
                map[nx][ny]='*';
                water.push(pr(nx,ny));
            }
        }

        while(hedgehogSize--){
            int x = hedgehog.front().first;
            int y = hedgehog.front().second;
            hedgehog.pop();

            if(Check[x][y]==visited) continue;
            Check[x][y]=visited;

            for(int i=0;i<4;i++){
                int nx=x+xx[i];
                int ny=y+yy[i];

                if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
                if(map[nx][ny]=='*' || map[nx][ny]=='X' || Check[nx][ny]==visited || map[nx][ny]=='S') continue;
                if(map[nx][ny]=='D') {
                    cout << cnt[x][y]+1 << endl;
                    return;
                }
                map[nx][ny]='S';
                cnt[nx][ny]=cnt[x][y]+1;
                hedgehog.push(pr(nx,ny));
            }
        }

    }
    cout << "KAKTUS" << endl;
}

int main(){
    int M,N;
    cin >> M >> N;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char k;
            cin >> k;
            map[i][j]=k;
            if(map[i][j]=='S') hedgehog.push(pr(i,j));
            if(map[i][j]=='*') water.push(pr(i,j));
        }
    }
    bfs(M,N);
}
