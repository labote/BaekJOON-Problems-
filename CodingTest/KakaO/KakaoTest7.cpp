//
//  KakaoTest7.cpp
//  Problems
//
//  Created by 홍민성 on 07/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,-1,0};
int cnt[MAX][MAX];
vector<vector<int>> vec;

int solution(vector<vector<int>> board, int yStart, int xStart, int N){ // dfs
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cout << board[i][j] << " ";
//        } cout << endl;
//    }
    queue<pair<int,int>> q;
    q.push(make_pair(yStart,xStart));
    q.push(make_pair(yStart,xStart+1));
//    cnt[yStart][xStart]=1;
//    cnt[yStart][xStart+1]=1;

    while(!q.empty()){
        int x=q.front().second;
        int y=q.front().first;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+xx[i];
            int ny=y+yy[i];

            if(0>nx || 0>ny || nx>=N || ny>=N || board[ny][nx]==1 || cnt[ny][nx]!=0) continue;
            cnt[ny][nx]=cnt[y][x]+1;
//            cout << ny << " " <<  nx << " " << cnt[ny][nx] << endl;
            q.push(make_pair(ny,nx));
        }
    }
    return cnt[N-1][N-1]-1;

//    return 0;
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        vector<int> element(num);
        vec.push_back(element);
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            int k;
            cin >> k;
            vec[i][j]=k;
        }
    }
    //solution(vec,0,0,num);
    cout <<solution(vec,0,0,num) << endl;
}
