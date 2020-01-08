//
//  Problem2606.cpp
//  Problems
//
//  Created by 홍민성 on 09/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 101
#define visited true
#define Non_visited false

using namespace std;

vector<int> computer[MAX];
bool Check[MAX];
int cnt;

void dfs(int x){
    if(Check[x]){
        return;
    }
    Check[x]=visited;
    cnt++;
    
    for(int i=0;i<computer[x].size();i++){
        int val = computer[x][i];
        dfs(val);
    }
}

int main(){
    int V,num;
    cin >> V >> num;
    
    for(int i=0;i<num;i++){
        int M,N;
        cin >> M >> N;

        computer[M].push_back(N);
        computer[N].push_back(M);
    }
    
    dfs(1);
    
    cout << cnt-1 << endl;
}

