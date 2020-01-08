//
//  MergeSort.cpp
//  Problems
//
//  Created by 홍민성 on 01/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int arry[9]={10,9,8,7,6,5,4,3,2};
int sorted[9];

void Merge(int start,int mid, int end){
    int i,j,k,l;
    i=start;
    k=start;
    j=mid+1;
    
    while(i<=mid && j<=end){
        if(arry[i]>arry[j]){
            sorted[k++]=arry[j++];
        }else{
            sorted[k++]=arry[i++];
        }
    }
    
    if(i>mid){
        for(int l=j;l<=end;l++){
            sorted[k++]=arry[l];
        }
    }
    else{
        for(int l=i;l<=mid;l++){
            sorted[k++]=arry[l];
        }
    }
    
    for(l=start;l<=end;l++){
        arry[l]=sorted[l];
    }
    
    
}

void MergeSort(int start, int end){
    int mid;
    
    if(start<end){
        mid=(start+end)/2;
        MergeSort(start,mid);
        MergeSort(mid+1,end);
        Merge(start,mid,end);
    }
}

int main(){
    
    MergeSort(0,8);
    
    for(int i=0;i<8;i++){
        cout << arry[i] << " ";
    }cout << endl;
}
