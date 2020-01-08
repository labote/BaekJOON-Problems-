//
//  Problem9663.cpp
//  Problems
//
//  Created by 홍민성 on 16/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int cnt;

// 배열의 index를 row로, 값을 column으로
bool isPossible(int *col,int row){
    for(int i=0;i<row;i++){
        if(col[i]==col[row] || abs(col[i]-col[row]) == abs(i-row)){
            return false;
        }
    }
    
//    for(int i=0; i<row; i++){
//        if(col[i]==col[row]){
//            return false;
//        }
//    }
    return true;
}

void nQueen(int input,int *col,int row){
    if(row==input)
        cnt++;
    else{
        for(int column=0; column<input; column++){
            col[row]=column;
            if(isPossible(col,row)){
                nQueen(input,col,row+1);
            }
        }
    }
}

int main(){
    int input;
    cin >> input;
    
    int *col = new int[input](); // 0으로 초기화까지 가능

    nQueen(input, col, 0);
    
    delete[] col;
    
    cout << cnt << endl;
}
