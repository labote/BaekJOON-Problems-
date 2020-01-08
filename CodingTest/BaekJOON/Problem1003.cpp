//
//  Problem1003.cpp
//  Problems
//
//  Created by 홍민성 on 10/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>

#define MAX 41

using namespace std;

int Test[MAX];

int fibonacci(int n) {
    if(n==-1){
        return 1;
    }
    if(n==0) {
        return 0;
    }
    if(n==1) {
        return 1;
    }
    if(Test[n]!=0) return Test[n];
    
    return Test[n] = fibonacci(n-1) + fibonacci(n-2);
    
}

int main(){
    int number;
    
    cin>>number;
    
    queue<int> q;
    
    for(int i=0;i<number;i++){
        int M;
        cin >> M;
        q.push(M);
    }
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
//        if(num>0){
//            cout << fibonacci(num-1) << " " << fibonacci(num)<< endl;
//        }
//        else
//            cout << "1 0" << endl;
        cout << fibonacci(num-1) << " " << fibonacci(num)<< endl;
    }
}
