//
//  Problem1932.cpp
//  Problems
//
//  Created by 홍민성 on 27/07/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 501

using namespace std;

//vector<int> tri[MAX];
int tri[MAX][MAX];
int value[MAX][MAX];

void dp(int number){
    
    for(int n=number;n>1;n--){
        for(int k=number;k>1;k--){
            tri[n-2][k-2] = tri[n-2][k-2] + max(tri[n-1][k-2], tri[n-1][k-1]); // 점화식 아래서부터 위로
        }
    }
}

int main(){
    int number;
    cin >> number;
    
//    for(int i=0; i<number; i++){
//        for(int j=number-1-i;j<number;j++){
//            int n;
//            cin >> n;
//            tri[i].push_back(n);
//        }
//    }

//  ------------------------------- 벡터로 풀었을때 틀린 이유는 뭘까?
    
    for(int i=0; i<number; i++){
        for(int j=0;j<i+1; j++){
            int n;
            cin >> n;
            tri[i][j] = n;
        }
    }
//    for(int i=0; i<number; i++){
//        for(int j=0;j<i+1; j++){
//            cout << tri[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    dp(number);
    
    cout << tri[0][0] << endl;
//    cout << tri[1][0] << endl;
}
