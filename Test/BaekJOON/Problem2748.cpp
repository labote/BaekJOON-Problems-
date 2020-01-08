//
//  Problem2748.cpp
//  Problems
//
//  Created by 홍민성 on 28/07/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

long long int arry[91];

long long int dp(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(arry[n]!=0) return arry[n];
    return arry[n] = dp(n-1) + dp(n-2);
}

// long long int 배열을 사용할때 리턴값 또한 long long int로 바꾸어야 한다. 계속 int dp()로 선언했기 때문에 arry[n]을 리턴할때 오류가 생겼음

int main(){
    int number;
    
    cin >> number;
    
    cout << dp(number) << endl;
}
