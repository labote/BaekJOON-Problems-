//
//  Problem5014.cpp
//  Problems
//
//  Created by 홍민성 on 26/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 1000001

using namespace std;

bool Check[MAX];
int cnt[MAX];

void BFS(int F, int S, int G, int U, int D){
    queue<int> q;
    q.push(S);
    
    if(S==G){
        cnt[G]=-1;
        return;
    }
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        
        if(Check[x]==visited) continue;
        if(x==G) break;
        
        Check[x]=visited;
        
        int nx=x+U;
        int ny=x-D;
        
        if(nx<=F && Check[nx]!=visited) {
            q.push(nx);
            cnt[nx]=cnt[x]+1;
        }
        if(ny>=1 && Check[ny]!=visited) {
            q.push(ny);
            cnt[ny]=cnt[x]+1;
        }
    }
}

int main(){
    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;
    
    BFS(F,S,G,U,D);
    
    if(cnt[G]==0){
        cout << "use the stairs" << endl;
    }else if(cnt[G]==-1){
        cout << 0 << endl;
    }else
        cout << cnt[G] << endl;
}
