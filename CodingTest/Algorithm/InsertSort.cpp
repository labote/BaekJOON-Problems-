//
//  InsertSort.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int data[9]={7,6,5,8,3,5,9,1,6};

void InsertSort(){
    int j;
    for(int i=0;i<8;i++){
        j=i;
        while(j>=0 && data[j]>data[j+1]){
            int temp;
            temp=data[j];
            data[j]=data[j+1];
            data[j+1]=temp;
            j--;
        }
    }
}

int main(){
    InsertSort();
    
    for(int i=0;i<9;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
