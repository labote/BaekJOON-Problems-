//
//  Problem9095.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 11
using namespace std;

int f[MAX];

int sum123(int num){
    
    if(num==0) return 0;
    if(num==1) return 1;
    if(num==2) return 2;
    if(num==3) return 4;
    if(f[num]!=0) return f[num];
    return f[num] = sum123(num-3) + sum123(num-2) + sum123(num-1);
}

int main(){
    int num;
    cin >> num;
    
    queue<int> q;
    
    for(int i=0; i<num; i++){
        int k;
        cin >> k;
        q.push(sum123(k));
    }
    
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

// 백트래킹, DP
