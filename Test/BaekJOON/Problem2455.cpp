//
//  Problem2455.cpp
//  Problems
//
//  Created by 홍민성 on 08/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pir;

queue<pir> q;
queue<int> ans;
int num;

int main(){
    int M,N;
    
    for(int i=0;i<4;i++){
        cin >> M >> N;
        q.push(pir(M,N));
    }
    
    while(!q.empty()){
        int Out=q.front().first;
        int In=q.front().second;
        q.pop();
        
        num-=Out;
        ans.push(num);
        num+=In;
        ans.push(num);
    }
    
    while(!ans.empty()){
        int x=ans.front();
        ans.pop();
        num=max(num,x);
    }
    cout << num << endl;
}
