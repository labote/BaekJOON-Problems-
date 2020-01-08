//
//  Problem5427.cpp
//  Problems
//
//  Created by 홍민성 on 25/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 1001

using namespace std;

char things[MAX][MAX];
char temp[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
bool visit[MAX][MAX];
int cnt[MAX][MAX];
queue<pair<int,int>> fire;
queue<pair<int,int>> sangguen;
vector<int> ans;

void Escape(int M,int N){
    while(!sangguen.empty()){
        
        long int Fnum = fire.size();
        long int Snum = sangguen.size();
        
        while(Fnum--){
            int x=fire.front().first;
            int y=fire.front().second;
            fire.pop();
            
            for(int i=0; i<4; i++){
                int nx=x+xx[i];
                int ny=y+yy[i];
                
                if(0>nx || nx>=M || 0>ny || ny>=N || things[nx][ny]=='*' || things[nx][ny]=='#') continue;
                    
                fire.push(make_pair(nx,ny));
                things[nx][ny]='*';
            }
        }
        
        while(Snum--){
            int x=sangguen.front().first;
            int y=sangguen.front().second;
            sangguen.pop();
            
            if(visit[x][y]==visited){
                continue;
            }
            visit[x][y]=visited;
            
            for(int i=0; i<4; i++){
                int nx=x+xx[i];
                int ny=y+yy[i];
                
                if(0>nx || nx>=M || 0>ny || ny>=N){
                    ans.push_back(cnt[x][y]+1);
                    return;
                }
                if(things[nx][ny]=='*' || things[nx][ny]=='#' || things[nx][ny]=='@' || visit[nx][ny]==visited) continue;
                sangguen.push(make_pair(nx,ny));
                //            things[x][y]='.';
                things[nx][ny]='@';
                cnt[nx][ny]=cnt[x][y]+1;
            }
        }
    }
    ans.push_back(0);
}

void Copy(int M, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp[i][j]=things[i][j];
        }
    }
}

void Reset(int M, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            things[i][j]=temp[i][j];
        }
    }
    while(!fire.empty()){
        fire.pop();
    }
    while(!sangguen.empty()){
        sangguen.pop();
    }
    memset(visit,Non_visited,sizeof(visit));
    memset(cnt,0,sizeof(cnt));
}

int main(){
    int num,tmp;
    cin >> num;
    
    tmp=num;
    
    while(num>0){
        int M,N;
        cin>>M>>N;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                char Cthings;
                cin >> Cthings;
                if(Cthings=='@'){
                    sangguen.push(make_pair(j,i));
                }
                if(Cthings=='*'){
                    fire.push(make_pair(j,i));
                }
                things[j][i]=Cthings;
            }
        }
        Copy(M,N);
        Escape(M,N);
        Reset(M,N);
        num--;
    }
    
    for(int i=0;i<tmp;i++){
        if(ans[i]==0){
            cout << "IMPOSSIBLE" << endl;
        }else
            cout << ans[i] << endl;
    }
    
}

