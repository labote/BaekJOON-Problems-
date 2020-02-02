//
//  QuickSort.cpp
//  Problems
//
//  Created by 홍민성 on 01/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int data[9]={7,6,5,8,3,5,9,1,6};

void QuickSort(int start, int end){
    if(start>=end){ // 원소가 1개인 경우
        return;
    }
    int pivot=start,i=start+1,j=end;
    int temp;
    
    while(i<=j){
        while(i<=end && data[i]<=data[pivot]){
            i++;
        }
        while(j>start && data[j]>=data[pivot]){
            j--;
        }
        
        if(i>j){
            temp=data[j];
            data[j]=data[pivot];
            data[pivot]=temp;
        }else{
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
    
    QuickSort(start,j-1);
    QuickSort(j+1, end);
}

int main(){

    QuickSort(0, 8);
    
    for(int i=0;i<9;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
