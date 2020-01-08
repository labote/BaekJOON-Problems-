//
//  Problem2161.cpp
//  Problems
//
//  Created by 홍민성 on 17/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void solve(){
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout << x << " ";
        int y=q.front();
        q.pop();
        q.push(y);
    }
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        q.push(i+1);
    }
    solve();
}
