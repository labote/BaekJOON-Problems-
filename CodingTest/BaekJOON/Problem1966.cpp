//
//  Problem1966.cpp
//  Problems
//
//  Created by 홍민성 on 13/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pir;
queue<pir> q;
queue<int> ANS;
priority_queue<int> order;
int cnt;

void Simulator(int Target){
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        int xx=order.top();
        
        if(x==xx){
            q.pop();
            order.pop();
            cnt++;
            
            if(Target==y){
                ANS.push(cnt);
                cnt=0;
                return;
            }
        }
        else{
            q.pop();
            q.push(pir(x,y));
        }
    }
}

void clear(){
    while(!q.empty() || !order.empty()){
        q.pop();
        order.pop();
    }
}

int main(){
    int num,N,M,Importance;
    cin >> num;
    
    while(num--){
        cin >> N >> M;
        
        for(int i=0;i<N;i++){
            cin >> Importance;
            q.push(pir(Importance,i));
            order.push(Importance);
        }
        Simulator(M);
        clear();
    }
    
    while(!ANS.empty()){
        int x=ANS.front();
        ANS.pop();
        cout << x << endl;
    }
}
