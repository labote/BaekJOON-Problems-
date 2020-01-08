//
//  Problem1697.cpp
//  Problems
//
//  Created by 홍민성 on 25/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 100001
using namespace std;

bool Check[MAX];

void bfs(int M, int N){
    queue<pair<int,int>> q;
    q.push(make_pair(M,0));
    
    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(0>x || x>MAX || Check[x]==visited){ // 2*x 의 크기 때문에 배열 인덱스 범위 초과
            continue;
        }
        Check[x]=visited;
        
        if(x==N){
            cout << cnt << endl;
            break;
        }
        q.push(make_pair(x+1,cnt+1));
        q.push(make_pair(x-1,cnt+1));
        q.push(make_pair(x*2,cnt+1));
    }
}

int main(){
    int M,N;
    cin >> M >> N;
    
    bfs(M,N);
}
