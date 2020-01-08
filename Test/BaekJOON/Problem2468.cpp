//
//  Problem2468.cpp
//  Problems
//
//  Created by 홍민성 on 22/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define visited true
#define Non_visited false
#define MAX 100

using namespace std;

int area[MAX][MAX];
bool Check[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int height;
int ans;

void Safe(int num, int x, int y){
    int nx, ny;
    
    if(Check[x][y]==visited){
        return;
    }
    
    Check[x][y] = visited;
    
    for(int i=0;i<4;i++){
        nx=x+xx[i];
        ny=y+yy[i];
        
        if(0<=nx && nx<num && 0<=ny && ny<num){
            if(Check[nx][ny]!=visited){
                Safe(num,nx,ny);
            }
        }
    }
}

void limit(int height, int x, int y){
    if(area[x][y] <= height){
        Check[x][y] = visited;
    }
}

void reset(){
    memset(Check,Non_visited,sizeof(Check));
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            int k;
            cin >> k;
            area[i][j] = k;
        }
    }
//    cout << endl;
//    
//    for(int i=0;i<num;i++){
//        for(int j=0;j<num;j++){
//            cout << Check[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    while(true){
        int cnt=0;
        
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                limit(height,i,j);
            }
        }
        
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(Check[i][j]!=visited){
                    Safe(num,i,j);
                    cnt++;
                }
            }
        }
        
        height++;
        ans=max(ans,cnt);
        reset();
        
        if(cnt==0){
            break;
        }
    }
    
    cout << ans << endl;
}
