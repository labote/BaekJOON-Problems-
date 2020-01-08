//
//  Problem2583.cpp
//  Problems
//
//  Created by 홍민성 on 27/07/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define visited true
#define Non_visited false

using namespace std;

int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
bool Check[MAX][MAX];
int area=1;
vector<int> ans;
vector<int> XY[MAX];

void dfs(int M, int N, int x, int y){
    
    int nx,ny;
    
    if(Check[x][y]){
        return;
    }
    
    Check[x][y]=visited;

    
    for(int i=0;i<4;i++){
        nx=x+xx[i];
        ny=y+yy[i];
        if(nx>=0 && ny>=0 && nx<N && ny<M){
            if(!Check[nx][ny]){
                area++;
                dfs(M,N,nx,ny);
            }
        }
    }
}
void XYCheck(int x1, int y1, int x2, int y2){
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            if(!Check[i][j]){
                Check[i][j]=visited;
            }
        }
    }
}

int main(){
    
    int M, N, K;
    int xy;
    cin >> M >> N >> K;
    
    for(int i=0;i<K;i++){
        for(int j=0;j<4;j++){
            cin >> xy;
            XY[i].push_back(xy);
        }
        XYCheck(XY[i][0],XY[i][1],XY[i][2],XY[i][3]);
    }
    
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << Check[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!Check[i][j]){
                dfs(M,N,i,j);
                ans.push_back(area);
                area=1;
            }
//            dfs(M,N,i,j);
//            ans.push_back(area);
        }
    }
    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    
}
