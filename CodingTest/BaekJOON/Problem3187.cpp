//
//  Problem3187.cpp
//  Problems
//
//  Created by 홍민성 on 03/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 251

using namespace std;

int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
char cArr[MAX][MAX];
bool Check[MAX][MAX];
int Sheep;
int Wolf;
queue<pair<int,int>> SheepWolf;

void bfs(int M, int N){
    
    while(!SheepWolf.empty()){
        int xStart=SheepWolf.front().first;
        int yStart=SheepWolf.front().second;
        SheepWolf.pop();
        
        if(Check[xStart][yStart]) continue;
        Check[xStart][yStart]=visited;
        
        queue<pair<int,int>> q;
        q.push(make_pair(xStart,yStart));
        
        int sheep=0;
        int wolf=0;
        
        if(cArr[xStart][yStart]=='k') sheep++;
        if(cArr[xStart][yStart]=='v') wolf++;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=x+xx[i];
                int ny=y+yy[i];
                
                if(nx<0 || nx>=M || ny<0 || ny>=N || cArr[nx][ny]=='#' || Check[nx][ny]) continue;
                if(cArr[nx][ny]=='k'){
                    Check[nx][ny]=visited;
                    sheep++;
                }
                if(cArr[nx][ny]=='v'){
                    Check[nx][ny]=visited;
                    wolf++;
                }
                if(cArr[nx][ny]=='.'){
                    Check[nx][ny]=visited;
                }
                q.push(make_pair(nx,ny));
            }
        }
        if(sheep>wolf){
            Sheep+=sheep;
        }
        else
            Wolf+=wolf;
    }
    
//    while(!sheep.empty()){
//        int x=sheep.front().first;
//        int y=sheep.front().second;
//        sheep.pop();
//
//        if(Check[x][y]) continue;
//
//        Check[x][y]=visited;
//
//        for(int i=0;i<4;i++){
//            int nx=x+xx[i];
//            int ny=y+yy[i];
//
//            if(nx<0 || nx>=M || ny<0 || ny>=N || cArr[nx][ny]=='#') continue;
//            if(cArr[nx][ny]=='k'){
//                Check[nx][ny]=visited;
//            }
//        }
//    }
}

int main(){
    int M,N; // 9 12 행 9 열 12 -> x좌표 12 y좌표 9
    cin>>M>>N;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char Char;
            cin >> Char;
            if(Char=='v' || Char=='k'){
                SheepWolf.push(make_pair(i,j));
            }
            cArr[i][j]=Char;
        }
    }
    bfs(M,N);
    cout << Sheep << " " << Wolf << endl;

//    for(int i=0;i<M;i++){
//        for(int j=0;j<N;j++){
//            cout << cArr[i][j] << " ";
//        }
//        cout << endl;
//    }
}
