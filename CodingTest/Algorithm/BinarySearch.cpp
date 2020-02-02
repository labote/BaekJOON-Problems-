//
//  BinarySearch.cpp
//  Problems
//
//  Created by 홍민성 on 18/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int data[9]={1, 3, 5, 5, 6, 6, 7, 8, 9};

void BinarySearch(int num, int start, int end){
    
    int result;
    
    while(start<=end){
        int mid = (start+end)/2;
        
        if(data[mid]>num){
            end=mid-1;
        }else if(data[mid]<num){
            start=mid+1;
        }else{
            result=mid;
            cout << result+1 << "번째 숫자입니다." << endl;
            return;
        }
    }
    cout << "존재하지 않습니다." << endl;
}

int main(){
    BinarySearch(6, 0, 8);
}
