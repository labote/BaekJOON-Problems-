//
//  Floyd Warshall Algorithm.cpp
//  Problems
//
//  Created by 홍민성 on 10/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

// '모든 정점'에서 '모든 정점'으로의 최단 경로를 구할때 사용
// '거쳐가는 정점'을 기준으로 최단 거리를 구하는 것

#include <iostream>

using namespace std;

int num=4;
int INF = 100000000;
int a[4][4]={
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};

void floydWarhsall(){
    int d[num][num];
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            d[i][j]=a[i][j];
        }
    }
    
    //k는 거쳐가는 노드
    for(int k=0;k<num;k++){
        //i는 출발 노드
        for(int i=0;i<num;i++){
            //j는 도착 노드
            for(int j=0;j<num;j++){
                if(d[i][k]+d[k][j] < d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    
    //결과를 출력
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    floydWarhsall();
}
