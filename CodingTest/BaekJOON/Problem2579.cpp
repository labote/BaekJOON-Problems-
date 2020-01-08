//
//  Problem2579.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define MAX 301

using namespace std;

int store[MAX];

int stair(int num, int *f){
    if(num==0) return 0;
    if(num==1) return store[num] = f[num];
    if(num==2) return store[num] = f[1] + f[2];
    if(store[num]!=0) return store[num];
    
    store[num] = max(f[num]+f[num-1]+stair(num-3,f),f[num]+stair(num-2,f));
    
    return store[num];
}

int main(){
    int num;
    cin >> num;
    
    int *f = new int[num+1]();
    
    for(int i=1;i<=num;i++){
        int n;
        cin >> n;
        f[i]=n;
    }
    cout << stair(num,f) << endl;
}
