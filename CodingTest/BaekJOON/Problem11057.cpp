//
//  Problem11057.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 1001
#define mod 10007

using namespace std;

int N,ans;
int arr[MAX][10];

void dp(){
    
    for(int i=0;i<10;i++){
        arr[1][i]=1;
    }
    
    for(int n=2;n<=N;n++){
        for(int i=0;i<10;i++){
            for(int j=0;j<=i;j++){
                arr[n][i]+=arr[n-1][j]%mod;
            }
        }
    }
}

int main(){
    cin >> N;
    
    dp();
    
    for(int i=0;i<10;i++){
        ans+=arr[N][i];
    }
    ans=ans%mod;
    cout << ans << endl;
}
