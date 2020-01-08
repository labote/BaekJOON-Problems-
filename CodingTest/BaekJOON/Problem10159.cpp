//
//  Problem10159.cpp
//  Problems
//
//  Created by 홍민성 on 23/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 101
#define INF 987654321

using namespace std;

void FloydWarshall(int **arry, int N){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arry[i][j]>arry[i][k]+arry[k][j]){
                    arry[i][j]=arry[i][k]+arry[k][j];
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arry[i][j]==INF){
                arry[i][j]=0;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(arry[i][j]!=0 || arry[j][i]!=0){
                arry[i][j]=1;
                arry[j][i]=1;
            }
        }
    }
    int cnt=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arry[i][j]==0){
                cnt++;
            }
        }
        cout << cnt-1 << '\n';
        cnt=0;
    }
}

int main(){
    int N;
    cin >> N;
    
    int** arry=new int*[N];
    for(int i=0;i<N;i++){
        arry[i]=new int[N];
    }
    
    int M;
    cin >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arry[i][j]=INF;
            if(i==j){
                arry[i][j]=0;
            }
        }
    }
    
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        arry[a-1][b-1]=1;
    }
    
    FloydWarshall(arry,N);
}
