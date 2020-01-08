//
//  Problem10026.cpp
//  Problems
//
//  Created by 홍민성 on 23/07/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 101
#define visited true
#define Non_visited false

using namespace std;

bool Check[MAX][MAX];
bool Check2[MAX][MAX];
vector<char> RGB[MAX];

int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
int C1, C2;

void dfs(int x, int y, int n){
    
    int nx, ny;
    
    if(Check[x][y]){
        return;
    }
    
    Check[x][y] = visited;
    
    for(int i=0; i < 4; i++){
        nx = x + xx[i];
        ny = y + yy[i];
        
        if(0 <= nx && nx < n && 0 <= ny && ny < n && RGB[x][y] == RGB[nx][ny]){
            dfs(nx,ny,n);
        }
    }
}

void dfs2(int x, int y, int n){
    
    int nx, ny;
    
    if(Check2[x][y]){
        return;
    }
    
    Check2[x][y] = visited;
    
    for(int i=0; i < 4; i++){
        nx = x + xx[i];
        ny = y + yy[i];
        
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(RGB[x][y] == RGB[nx][ny]){
                dfs2(nx,ny,n);
            }
            else if((RGB[x][y] == 'R' && RGB[nx][ny] == 'G') || (RGB[x][y] == 'G' && RGB[nx][ny] == 'R')){
                dfs2(nx,ny,n);
            }
//            if(RGB[nx][ny] == 'G'){
//                RGB[nx][ny] = 'R';
//            }
//            if(RGB[x][y] == RGB[nx][ny]){
//                dfs(nx,ny,n);
//            }
        }
//        if(0 <= nx && nx < n && 0 <= ny && ny < n && RGB[x][y] == RGB[nx][ny]){
//            dfs(nx,ny,n);
//        }
    }
    //return visited;
}
// RG 같다
int main(){
    int number;
    
    cin >> number;
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            char color;

            cin >> color;
            
            RGB[i].push_back(color);
        }
    }
//    for(int i=0; i<number; i++){
//        for(int j=0; j<number; j++){
//            cout << RGB[i][j];
//        }
//        cout << endl;
//    }
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            if(!Check[i][j]){
                C1++;
                dfs(i,j,number);
            }
        }
    }
    
    //memset(Check, false, sizeof(Check));
    
//    for(int i=0; i<number; i++){
//        for(int j=0; j<number; j++){
//            if(RGB[i][j] == 'G'){
//                RGB[i][j] = 'R';5
//            }
//        }
//    }
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            if(!Check2[i][j]){
                C2++;
                dfs2(i,j,number);
            }
        }
    }
    cout << C1 << " " << C2 << endl;
}

