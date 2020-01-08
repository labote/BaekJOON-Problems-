//
//  Problem13976.cpp
//  Problems
//
//  Created by 홍민성 on 01/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(matrix &a, matrix &b){
    long long n=a.size();
    matrix c(n,vector<long long>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j]%mod;
                c[i][j] = (c[i][j]+mod)%mod; // 이유가 뭘까?
            }
            //c[i][j]%=mod;
        }
    }
    return c;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long M;
    
    cin >> M;
    
    matrix A = {{4,-1},{1,0}}; // A
    matrix U0 = {{1,0},{1,0}}; // 처음 초기값
    matrix U1 = {{0,0},{0,0}}; // 곱해서 0을 만들어주기 위해
    matrix ans = {{1,0},{0,1}};
    
    if(M%2==1){
        ans=ans*U1;
    }else{
        long long N = M/2;
        while(N!=0){
            if(N%2==1){
                ans=ans*A;
            }
            A=A*A;
            N/=2;
        }
        ans=ans*U0;
    }
    cout << ans[0][0] << endl;
    
//        while(M!=0){
//            if(M%2==1){
//                ans=ans*A; // 분할하기 전에 홀수인 경우 a의 값을 미리 저장해준다
//            }
//            A=A*A;
//            M/=2;
//        }
//    cout << ans[0][1] << endl;
    
//    long long N = M/2;
//
//    while(M!=0){
//
//    }
//    if(M%2==1){
//        ans=ans*U1;
//    }
//    else
//        ans=ans*U0;
//
//    cout << ans[0][0] << endl;
//
    //    matrix b = {{1,0},{0,1}}; // b는 단위행렬
    //    matrix a = {{1,1},{1,0}};
    //
    //    while(M!=0){
    //        if(M%2==1){
    //            b=b*a; // 분할하기 전에 홀수인 경우 a의 값을 미리 저장해준다
    //        }
    //        a=a*a;
    //        M/=2;
    //    }

//    if(M%2==1){
//        ans=ans*U1;
//    }
//    else{
//        M=M/2;
//        while(M!=0){
//            A=A*A;
//            M/=2;
//        }
//        ans=ans*U0;
//    }
//    cout << ans[0][0] << endl;
}
