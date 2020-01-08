//
//  Problem1987.cpp
//  Problems
//
//  Created by 홍민성 on 06/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#define visited true
#define Non_visited false
#define MAX 21

using namespace std;

vector<char> Alph;
char cArr[MAX][MAX];
bool Check[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int M,N;
int ans;

// 1. 알파벳 배열을 만들어서 비교할지
// 2. 들어오는 알파벳만 저장해서 비교할지 - 큐를 쓸지, 덱을 쓸지, 벡터를 쓸지

bool check(int y, int x){
    for(unsigned int i=0;i<Alph.size();i++){
        if(cArr[y][x]==Alph[i]){
            return false;
        }
    }
    return true;
}

//void  reset(){
//    while(!Alph.empty()){
//        Alph.pop_back();
//    }
//    memset(Check,Non_visited,sizeof(Check));
//}

void dfs(int y, int x, int cnt){
    
//    if(Check[y][x]) return;
//    Check[y][x]=visited;

    ans=max(ans,cnt);
    
    for(int i=0;i<4;i++){
        int nx=x+xx[i];
        int ny=y+yy[i];
        
//        if(0>nx || 0>ny || nx>=N || ny>=M || Check[ny][nx]) continue;
        if(0>nx || 0>ny || nx>=N || ny>=M) continue;
        if(check(ny,nx)){
            Alph.push_back(cArr[ny][nx]);
            dfs(ny,nx,cnt+1);
            Alph.pop_back();
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> M >> N;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char Char;
            cin >> Char;
            cArr[i][j]=Char;
        }
    }
    Alph.push_back(cArr[0][0]);
    dfs(0,0,1);
    
    cout << ans << '\n';
//        for(int i=0;i<M;i++){
//            for(int j=0;j<N;j++){
//                cout << cArr[i][j];
//            }cout << endl;
//        }
//    for(int i=0;i<Alph.size();i++){
//        cout << Alph[i] << " ";
//    }
//    cout << endl;
}
