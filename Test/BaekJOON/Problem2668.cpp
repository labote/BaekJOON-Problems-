//
//  2668.cpp
//  Problems
//
//  Created by 홍민성 on 29/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <cstring>
#define visited true
#define Non_visited false
#define MAX 101
using namespace std;

int arr[MAX];
int cycle[MAX];
bool check[MAX];
int cnt;

void dfs(int start, int current, int num){
    if(cycle[current]>0) return;
    
    int Next = arr[current];
    if(check[current]){
        if(start==current){
            for(int i=1;i<=num;i++){
                if(check[i]) {
                    cycle[i]++;
                    cnt++;
                }
            }
        }
    }
    else{
        check[current]=visited;
        dfs(start,Next,num);
    }
}

int main(){
    int num;
    cin >> num;
    
    for(int i=1;i<=num;i++){
        int n;
        cin >> n;
        arr[i]=n;
    }
    for(int i=1;i<=num;i++){
        dfs(i,i,num);
        memset(check, Non_visited, sizeof(check));
    }
    cout << cnt << endl;
    for(int i=1;i<=num;i++){
        if(cycle[i]>0){
            cout << i << endl;
        }
    }
}
