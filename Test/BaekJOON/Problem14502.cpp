//
//  Problem14502.cpp
//  Problems
//
//  Created by 홍민성 on 07/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define visited true
#define Non_visited false
#define MAX 8

using namespace std;

int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
bool Check[MAX][MAX];
vector<int> MAP[MAX];
vector<int> CopyMAP[MAX];
int area;
int ans;
int cnt;
int N,M;

void virus(int x, int y){ // 바이러스 채우기
    int nx,ny;
    
    if(Check[x][y]){
        return;
    }
    
    Check[x][y]=visited;
    
    for(int i=0;i<4;i++){
        nx=x+xx[i];
        ny=y+yy[i];
        
        if(nx>=0 && ny>=0 && nx<N && ny<M && MAP[nx][ny]==0){
            MAP[nx][ny]=2;
            virus(nx,ny);
        }
    }
}
void Copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            CopyMAP[i][j] = MAP[i][j];
        }
    }
}

void Restore(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            MAP[i][j] = CopyMAP[i][j];
        }
    }
    memset(Check,Non_visited,sizeof(Check));
}

void Safe(){
    area=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(MAP[i][j]==0){
                area++;
            }
        }
    }
}

void Walldfs(int depth){
    if(depth==3){
        Copy();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(MAP[i][j]==2){
                    virus(i,j);
                }
            }
        }
//        for(int i=0;i<N;i++){
//            for(int j=0;j<M;j++){
//                cout << MAP[i][j] << " ";
//            }
//            cout << endl;
//        }
        Safe();
        Restore();
        ans=max(ans,area);
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(MAP[i][j]==0){
                MAP[i][j]=1;
                Walldfs(depth+1);
                MAP[i][j]=0;
            }
        }
    }

//    cout << area << endl;
}

void Walldfs2(){
    if(cnt==3){
        Copy();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(MAP[i][j]==2){
                    virus(i,j);
                }
            }
        }
        //        for(int i=0;i<N;i++){
        //            for(int j=0;j<M;j++){
        //                cout << MAP[i][j] << " ";
        //            }
        //            cout << endl;
        //        }
        Safe();
        Restore();
        ans=max(ans,area);
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(MAP[i][j]==0){
                MAP[i][j]=1;
                cnt+=1;
                Walldfs2();
                cnt-=1;
                MAP[i][j]=0;
            }
        }
    }
    //--> 전역 변수 cnt를 사용하게 되면 처음에 MAP[0][0], MAP[0][1], MAP[0][2] 세우고 그다음에 cnt가 2가 되어야 MAP[0][0], MAP[0][1], MAP[0][3]에 벽에 세워지고 cnt=3이 되어 그 과정을 반복해 끝까지 찾게 된다. 처음에 if(cnt==3)에 cnt=0을 넣었을때 거기서 다시 벽을 또 3개 세우게 되고 계속 그것을 반복하게 되어 실패한 것 같다.
    
    //    cout << area << endl;
}

int main(){

    int input;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> input;
            MAP[i].push_back(input);
            CopyMAP[i].push_back(input);
        }
    }

//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            if(MAP[i][j]==2){
//                virus(i,j);
//            }
//        }
//    }
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << MAP[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    Safe();
//    Restore();
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << Check[i][j] << " ";
//        }
//        cout << endl;
//    }
    
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            if(MAP[i][j]==0){
//                MAP[i][j]=1;
//                Walldfs(1);
//                MAP[i][j]=0;
//            }
//        }
//    }
//    Walldfs(0);
    Walldfs2();
//    cout << area << endl;
    cout << ans << endl;
}
