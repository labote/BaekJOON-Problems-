//
//  Problem11652.cpp
//  Problems
//
//  Created by 홍민성 on 28/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> vec;
vector <long long> sorted;
long long Max;
int MaxCnt;
int p,cnt;

void merge(vector<long long> &list, int left, int mid, int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        if(list[i]<list[j]){
            sorted[k++]=list[i++];
        }
        else if(list[i]==list[j]){
            if(list[i]<=list[j]){
                sorted[k++]=list[i++];
            }else{
                sorted[k++]=list[j++];
            }
            
        }
        else{
            sorted[k++]=list[j++];
        }
    }
    if(i>mid){
        for(l=j;l<=right;l++){
            sorted[k++]=list[l];
        }
    }
    else{
        for(l=i;l<=mid;l++){
            sorted[k++]=list[l];
        }
    }
    for(l=left;l<=right;l++){
        list[l]=sorted[l];
    }
}

void mergeSort(vector<long long> &list, int left, int right){
    int mid;
    
    if(left<right){
        mid=(left+right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list,left,mid,right);
    }
}


int main(){
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        long long M;
        cin >> M;
        vec.push_back(M);
    }
    
    sorted = vector<long long> (N);
    mergeSort(vec,0,N-1);
    
    //sort(vec.begin(),vec.end());
    
    for(int i=0;i<N-1;i++){
        if(vec[i]<vec[i+1]){
            cnt=0;
            Max=vec[i+1];
        }else{
            cnt++;
        }
        
        if(MaxCnt<cnt){
            MaxCnt=cnt;
            p=i;
        }
    }
    cout << vec[p] << endl;
}

