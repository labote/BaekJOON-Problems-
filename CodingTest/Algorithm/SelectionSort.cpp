//
//  SelectionSort.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int data[9]={7,6,5,8,3,5,9,1,6};

void SelectionSort(){
    int Min;
    
    for(int i=0;i<8;i++){
        Min=i;
        for(int j=i+1;j<9;j++){
            if(data[Min]>data[j]){
                Min=j;
            }
        }
        if(i!=Min){
            int temp=data[i];
            data[i]=data[Min];
            data[Min]=temp;
        }
    }
}

int main(){
    SelectionSort();
    
    for(int i=0;i<9;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
