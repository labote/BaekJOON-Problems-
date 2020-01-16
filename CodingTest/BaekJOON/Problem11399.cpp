//
//  Problem11399.cpp
//  Problems
//
//  Created by 홍민성 on 16/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int P[MAX];
int N;
int ans;

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> P[i];
    }
    
    sort(P,P+N);
    
    for(int i=1;i<N;i++){
        P[i]+=P[i-1];
    }
    
    for(int i=0;i<N;i++){
        ans+=P[i];
    }
    
    cout << ans << endl;
}
