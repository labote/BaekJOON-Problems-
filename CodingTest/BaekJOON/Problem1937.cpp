////
////  Problem1937.cpp
////  Problems
////
////  Created by 홍민성 on 04/08/2019.
////  Copyright © 2019 홍민성. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define visited true
//#define Non_visited false
//#define MAX 501
//
//using namespace std;
//
//bool Check[MAX][MAX];
//int var[MAX][MAX] = {-1,};
//vector<int> Food[MAX];
//int Count;
//int Count2;
//int cmp1, cmp2;
//int xx[4] = {1,0,-1,0};
//int yy[4] = {0,1,0,-1};
//
//void dfs(int x, int y, int num){
//
//    if(Check[x][y]){
//        return;
//    }
//
//    Check[x][y] = visited;
//    Count++;
//
//    for(int i=0; i<4; i++){
//        int nx, ny;
//
//        cmp1 = Food[x][y];
//
//        nx = x+xx[i];
//        ny = y+yy[i];
//
//        if(0<=nx && nx<num && 0<=ny && ny<num){
//            cmp2 = Food[nx][ny];
//
//            if(cmp1<cmp2){
//                dfs(nx,ny,num);
//            }
//
//        }
//    }
//}
//
//int main(){
//    int number;
//    cin >> number;
//
//    for(int i=0; i<number; i++){
//        for(int j=0; j<number; j++){
//            int food;
//            cin >> food;
//            Food[i].push_back(food);
//        }
//    }
//
//    for(int i=0; i<number; i++){
//        for(int j=0; j<number; j++){
//            if(!Check[i][j]){
//                dfs(i,j,number);
//                Count2 = max(Count, Count2);
//                Count = 0;
//            }
//        //    cout << Food[i][j];
//        }
//      //  cout << endl;
//    }
//
//    cout << Count2 << endl;
//
//}
//
//

#include <iostream>
#include <vector>
#define MAX 501

using namespace std;

vector<int> Food[MAX];
int var[MAX][MAX];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int day=1;

int dfs(int x, int y, int num){
    int nx, ny;
    
    if(var[x][y]){
        return var[x][y];
    }
    
    for(int i=0;i<4;i++){
        nx=x+xx[i];
        ny=y+yy[i];
        
        if(0<=nx && nx<num && 0<=ny && ny<num && Food[x][y]<Food[nx][ny]){
            var[x][y]=max(var[x][y],dfs(nx,ny,num));
        }
    }
    
    var[x][y]++;
    return var[x][y];
}

int main(){
    int number;
    cin >> number;
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            int food;
            cin >> food;
            Food[i].push_back(food);
        }
    }
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            day=max(day,dfs(i,j,number));
        }
    }
    cout << day << endl;
}
