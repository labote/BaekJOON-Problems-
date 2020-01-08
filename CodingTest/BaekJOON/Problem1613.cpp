//
//  Problem1613.cpp
//  Problems
//
//  Created by 홍민성 on 05/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

vector<vector<int>> vec;
vector<int> v;
vector<int> ans;

void floydWarshall(int N){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(vec[i][k]+vec[k][j]<vec[i][j]){
                    vec[i][j]=vec[i][k]+vec[k][j];
                }
            }
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    
    v=vector<int> (n,0);
    
    for(int i=0;i<n;i++){
        vec.push_back(v);
    }
    
    int M,N;

    for(int i=0;i<k;i++){
        cin >> M >> N;
        vec[M-1][N-1]=1;
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
        }
    }
    
    int s,num;
    cin >> s;
    
    while(s--){
        cin >> M >> N;
        if(vec[M-1][N-1]>0){
            num=-1;
        }else if(vec[N-1][M-1]>0){
            num=1;
        }else{
            num=0;
        }
        ans.push_back(num);
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
