//
//  Problem11404.cpp
//  Problems
//
//  Created by 홍민성 on 10/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 100001

using namespace std;

vector<vector<int>> vec;
vector<int> v;

void floydWarshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vec[i][k]+vec[k][j] < vec[i][j]){
                    vec[i][j]=vec[i][k]+vec[k][j];
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    
    int a,b,c;
    
    v=vector<int>(n,0);
    
    for(int i=0;i<n;i++){
        vec.push_back(v);
    }
    
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        if(vec[a-1][b-1]!=0){
            c=min(vec[a-1][b-1],c);
        }
        vec[a-1][b-1]=c;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && vec[i][j]==0){
                vec[i][j]=INF;
            }
        }
    }

    floydWarshall(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vec[i][j]==INF){
                vec[i][j]=0;
            }
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
