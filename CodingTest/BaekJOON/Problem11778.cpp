//
//  Problem11778.cpp
//  Problems
//
//  Created by 홍민성 on 23/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(matrix &a, matrix &b){
    long int n=a.size();
    matrix c(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j]%mod;
                c[i][j]=(c[i][j]+mod)%mod;
            }
        }
    }
    return c;
}

long long Euclidean(long long M, long long N){
    long long remainder = 0;
    
    remainder = N ? Euclidean(N,M%N) : M;
    
    return remainder;
}

int main(){
    long long N,M;
    cin >> N >> M;
    
    matrix ans={{1,0},{0,1}};
    matrix a={{1,1},{1,0}};
    
    long long b = Euclidean(M,N);
    
    while(b>0){
        if(b%2==1){
            ans=ans*a;
        }
        a=a*a;
        b/=2;
    }
    cout << ans[0][1]%mod << endl;
}
