//
//  Problem6359.cpp
//  Problems
//
//  Created by 홍민성 on 30/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#define visited true
#define Non_visited false
#define MAX 101

using namespace std;

bool Check[MAX];
queue<int> q;

void Change(){
    
    while(!q.empty()){
        int cnt=0;
        memset(Check,Non_visited,sizeof(Check));
        int x=q.front();
        q.pop();
        
        for(int i=1;i<=x;i++){
            for(int j=i;j<=x;j+=i){
                Check[j]=!Check[j];
            }
        }
        for(int i=1;i<=x;i++){
            if(Check[i]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        int k;
        cin >> k;
        q.push(k);
    }
    Change();
}
