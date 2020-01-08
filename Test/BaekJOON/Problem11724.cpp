//
//  Problem11724.cpp
//  Problems
//
//  Created by 홍민성 on 01/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 1001
#define visited true
#define Non_visited false
using namespace std;

bool Check[MAX];
vector<int> VE[MAX];
vector<vector<int>> VE2;

int cnt;

void dfs(int k){
    if(Check[k]) return;
    
    Check[k]=visited;
    
    for(int i=0;i<VE2[k].size();i++){
        int x = VE2[k][i];
        dfs(x);
    }
}

int main(){
    int M,N;
    cin >> M >> N;
    
    VE2.resize(M+1);
    
    while(N--){
        int num1,num2;
        cin >> num1 >> num2;
//        VE[num1].push_back(num2);
//        VE[num2].push_back(num1);
        VE2[num1].push_back(num2);
        VE2[num2].push_back(num1);
    }
    
    for(int i=1;i<=M;i++){
        if(Check[i]==Non_visited){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}
