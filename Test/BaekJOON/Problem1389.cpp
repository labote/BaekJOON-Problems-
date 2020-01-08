//
//  Problem1389.cpp
//  Problems
//
//  Created by 홍민성 on 15/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 101
#define visited true
#define Non_visited false

using namespace std;

vector<int> vec[MAX];
vector<int> v;
bool check[MAX];
int M,N;
int ans;

void dfs(int x){
    if(check[x]==visited){
        return;
    }
    check[x]=visited;
    
    v.push_back(x);
    cout << x << endl;
    for(int i=0;i<vec[x].size();i++){
        int y=vec[x][i];
        dfs(y);
    }
}

int main(){
    
    cin >> M >>N;
    
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1);
    
//    cout << ans << endl;
//    for(int i=0;i<v.size();i++){
//        ans++;
//    }
//    cout << ans+1 << endl;
}

//
