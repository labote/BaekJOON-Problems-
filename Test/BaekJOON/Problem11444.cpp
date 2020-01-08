
//
//  Problem11444.cpp
//  Problems
//
//  Created by 홍민성 on 10/09/2019.
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
                c[i][j]+=a[i][k]*b[k][j];
            }
            c[i][j]%=mod;
        }
    }
    return c;
}

int main(){
    long long M;
    cin >> M;
    
    matrix b = {{1,0},{0,1}}; // b는 단위행렬
    matrix a = {{1,1},{1,0}};
    
    while(M!=0){
        if(M%2==1){
            b=b*a; // 분할하기 전에 홀수인 경우 a의 값을 미리 저장해준다
        }
        a=a*a;
        M/=2;
    }
    cout << b[0][1] << endl;
}
