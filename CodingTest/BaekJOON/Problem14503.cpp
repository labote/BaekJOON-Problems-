//
//  Problem14503.cpp
//  Problems
//
//  Created by 홍민성 on 17/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define visited true
#define Non_visited false
#define MAX 51

using namespace std;

int N,M,r,c,d;
int arry[MAX][MAX];
int xx[4]={0,1,0,-1}; // 1이면 동쪽, 3이면 서쪽
int yy[4]={-1,0,1,0}; // 2면 남쪽, 0이면 북쪽
int cnt;

// d=0이면 북쪽, 1이면 동쪽, 2면 남쪽, 3이면 서쪽
// 왼쪽으로 돌리면
// 서쪽, 남쪽, 동쪽, 북쪽
// 3 , 2 , 1 , 0

void clean(int r, int c, int d){
    if(arry[r][c]==1){
        return;
    }
    
    if(arry[r][c]==0){
        arry[r][c]=2;
        cnt++;
    }
    
    for(int i=0;i<4;i++){
        int nd=(d+3)%4;
        int nr=r+yy[nd];
        int nc=c+xx[nd];
        
        if(nr<0 || nc<0 || nr>=N || nc>=M) {
            d=nd;
            continue;
        }
        if(arry[nr][nc]==0){
            clean(nr,nc,nd);
            return;
        }
        else{
            d=nd;
        }
    }
    
    int nd=(d+2)%4;
    int nr=r+yy[nd];
    int nc=c+xx[nd];
    
    if(nr>=0 && nc>=0 && nr<N && nc<M){
        clean(nr,nc,d);
    }
}

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    
    int num;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> num;
            arry[i][j]=num;
        }
    }

    clean(r,c,d);
    
    cout << cnt << endl;
}
