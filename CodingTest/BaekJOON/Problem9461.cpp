//
//  Problem9461.cpp
//  Problems
//
//  Created by 홍민성 on 25/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 101

using namespace std;

long long dp[MAX];

//void fire(int value){
//    dp[1]=1;
//    dp[2]=1;
//    dp[3]=1;
//
//    for(int i=4;i<=value;i++){
//        dp[i]=dp[i-2]+dp[i-3];
//    }
//
//    cout << dp[value] << endl;
//}

long long fire(int value){
    if(value==1) return 1;
    if(value==2) return 1;
    if(value==3) return 1;
    if(dp[value]!=0) return dp[value];
    return dp[value] = fire(value-2)+fire(value-3);
}

int main(){
    int num;
    cin >> num;
    
    int *iArr = new int[num]();
    
    for(int i=0;i<num;i++){
        int value;
        cin >> value;
        iArr[i]=value;
    }
//    for(int i=0;i<num;i++){
//        fire(iArr[i]);
//    }
    for(int i=0;i<num;i++){
        cout << fire(iArr[i]) << endl;
    }
}
