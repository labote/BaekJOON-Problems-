//
//  Problem2146.cpp
//  Problems
//
//  Created by 홍민성 on 11/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

//#include <iostream>
//#include <queue>
//#define visited true
//#define Non_visited false
//#define MAX 101
//
//using namespace std;
//typedef pair<int,int> pir;
//
//int Map[MAX][MAX];
//int Number[MAX][MAX]; // 섬 숫자
//bool check[MAX][MAX];
//int xx[4]={1,0,-1,0};
//int yy[4]={0,1,0,-1};
//queue<pir> Island;
//
//void islandFind(int N, int x, int y, int cnt){
//    check[x][y]=visited;
//    Number[x][y]=cnt;
//
//    for(int i=0;i<4;i++){
//        int nx=x+xx[i];
//        int ny=y+yy[i];
//
//        if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
//        if(Map[nx][ny]==1 && check[nx][ny]!=visited){
//            islandFind(N,nx,ny,cnt);
//        }
//    }
//}
//
//void Connect(int N){
//
//
//}
//
//int main(){
//    int num,N;
//    cin >> N;
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cin >> num;
//            Map[i][j]=num;
//        }
//    }
//
//    int cnt=1;
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            if(Map[i][j]==1 && check[i][j]!=visited){
//                islandFind(N,i,j,cnt++);
//            }
//        }
//    }
//    cout << endl;
//
//    //    for(int i=0;i<N;i++){
//    //        for(int j=0;j<N;j++){
//    //            cout << Number[i][j] << " ";
//    //        }cout << endl;
//    //    }
//
//}
//

#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

typedef pair<int,int> pir;

int Map[MAX][MAX];
int temp[MAX][MAX];
int cnt[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
bool flag;
queue<pir> Island;
queue<pir> q;
queue<int> ans;
int x=9999;

void islandStart(int N){
    // 하나의 섬만 선택
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(Map[i][j]==1){
                Island.push(pir(i,j));
                cout << i << " " << j << endl;
                q.push(pir(i,j));
                Map[i][j]=2;
                return;
            }
        }
    }
    flag=false;
}

void islandCheck(int N){
    
    while(!Island.empty()){
        int firstIslandX = Island.front().first;
        int firstIslandY = Island.front().second;
        Island.pop();
        
        for(int i=0;i<4;i++){
            int nx=firstIslandX+xx[i];
            int ny=firstIslandY+yy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(Map[nx][ny]==1){
                Map[nx][ny]=2;
                Island.push(pir(nx,ny));
                q.push(pir(nx,ny));
            }
        }
    }
}

void copy(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            temp[i][j]=Map[i][j];
        }
    }
}

void change(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Map[i][j]=temp[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt[i][j]=0;
        }
    }
}

void bfs(int N){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+xx[i];
            int ny=y+yy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N || Map[nx][ny]==2) continue;
            if(Map[nx][ny]==0){
                Map[nx][ny]=2;
                cnt[nx][ny]=cnt[x][y]+1;
                q.push(pir(nx,ny));
            }
            if(Map[nx][ny]==1){
                ans.push(cnt[x][y]);
                //cout << cnt[x][y] << endl;
                return;
            }
        }
    }
}

void init(int N){
    flag=true;
    while(flag){
        islandStart(N);
        islandCheck(N);
        
//        cout << endl;
//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                cout << Map[i][j] << " ";
//            }cout << endl;
//        }
//
        copy(N);
//        cout << endl;
//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                cout << temp[i][j] << " ";
//            }cout << endl;
//        }
        bfs(N);
//        cout << endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << Map[i][j] << " ";
            }cout << endl;
        }
        change(N);
    }
}

int main(){
    int num,N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> num;
            Map[i][j]=num;
        }
    }
    
    init(N);
    
    while(!ans.empty()){
        int y=ans.front();
        ans.pop();
        cout << y << endl;
    }
}
