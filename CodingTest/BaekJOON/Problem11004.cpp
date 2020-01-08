//
//  Problem11004.cpp
//  Problems
//
//  Created by 홍민성 on 15/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> sorted;

void merge(vector<int> &list, long int left, long int middle, long int right){
    long int i,j,k,l;
    i=left;
    j=middle+1;
    k=left;
    
    while(i<=middle && j<=right){
        if(list[i]<=list[j]) sorted[k++]=list[i++];
        else sorted[k++]=list[j++];
    }
    
    if(i>middle){
        for(l=j;l<=right;l++){
            sorted[k++]=list[l];
        }
    }
    else{
        for(l=i;l<=middle;l++){
            sorted[k++]=list[l];
        }
    }
    for(l=left;l<=right;l++){
        list[l]=sorted[l];
    }
    
}

void mergeSort(vector<int> &list, long int left, long int right){
    long int middle;
    
    if(left<right){
        middle=(left+right)/2;
        mergeSort(list,left,middle);
        mergeSort(list,middle+1,right);
        merge(list,left,middle,right);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int M,N,num;
    cin >> M >> N;
    
    for(int i=0;i<M;i++){
        cin >> num;
        vec.push_back(num);
    }

    sorted = vector<int> (M,0);
    
    mergeSort(vec,0,M-1);
    
    cout << sorted[N-1] << endl;
}
