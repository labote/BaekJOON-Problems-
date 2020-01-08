//
//  Problem1431.cpp
//  Problems
//
//  Created by 홍민성 on 19/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> vec;
vector<string> sorted;

void Merge(int left, int mid, int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        long int leftsize=vec[i].size();
        long int rightsize=vec[j].size();
        
        if(leftsize>rightsize){
            sorted[k++]=vec[j++];
        }
        else if(leftsize==rightsize){
            int leftsum=0;
            int rightsum=0;
            
            for(int n=0;n<leftsize;n++){
                if(vec[i][n]>='0' && vec[i][n]<='9'){
                    leftsum+=vec[i][n]-'0';
                }
            }
            for(int n=0;n<rightsize;n++){
                if(vec[j][n]>='0' && vec[j][n]<='9'){
                    rightsum+=vec[j][n]-'0';
                }
            }
            
            if(leftsum>rightsum){
                sorted[k++]=vec[j++];
            }
            else if(leftsum==rightsum){
                if(vec[i]>vec[j]){
                    sorted[k++]=vec[j++];
                }
                else{
                    sorted[k++]=vec[i++];
                }
            }
            else{
                sorted[k++]=vec[i++];
            }
        }
        else{
            sorted[k++]=vec[i++];
        }
    }
    
    if(i>mid){
        for(int l=j;l<=right;l++){
            sorted[k++]=vec[l];
        }
    }else{
        for(int l=i;l<mid+1;l++){
            sorted[k++]=vec[l];
        }
    }
    
    for(l=left;l<=right;l++){
        vec[l]=sorted[l];
    }
}

void MergeSort(int left, int right){
    int mid;
    
    if(left<right){
        mid=(left+right)/2;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
}


int main(){
    int num;
    cin >> num;
    
    string str;
    
    for(int i=0;i<num;i++){
        cin >> str;
        vec.push_back(str);
    }
    
    sorted=vector<string> (num,"0");
    
    MergeSort(0, num-1);
    
    for(int i=0;i<num;i++){
        cout << vec[i] << endl;
    }
}
