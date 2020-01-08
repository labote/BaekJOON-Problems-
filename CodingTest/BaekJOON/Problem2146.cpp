//
//  Problem2146.cpp
//  Problems
//
//  Created by 홍민성 on 11/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 101

using namespace std;

int Map[MAX][MAX];
bool Check[MAX][MAX];

void dfs(){
    
}

int main(){
    int num;
    cin >> num;
    
    int N;
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin >> N;
            Map[i][j]=N;
        }
    }
//    cout << endl;
//
//    for(int i=0;i<num;i++){
//        for(int j=0;j<num;j++){
//            cout << Map[i][j] << " ";
//        }cout << endl;
//    }
}
