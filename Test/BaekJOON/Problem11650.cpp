//
//  Problem11650.cpp
//  Problems
//
//  Created by 홍민성 on 18/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

typedef pair<int,int> pir;
vector<pir> vec;
vector<pir> sorted;

void merge(vector<pir> &list, int left, int mid, int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        if(list[i].first<list[j].first){
            sorted[k++]=list[i++];
        }
        else if(list[i].first==list[j].first){
            if(list[i].second<=list[j].second){
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

void mergeSort(vector<pir> &list, int left, int right){
    int mid;
    
    if(left<right){
        mid=(left+right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list,left,mid,right);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int num;
    cin >> num;
    
    sorted = vector<pir> (num);
    
    for(int i=0;i<num;i++){
        int M,N;
        cin >> M >> N;
        vec.push_back(pir(M,N));
    }

    mergeSort(vec,0,num-1);
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << '\n';
    }
//    for(int i=0;i<num;i++){
//        if(!vec[i].empty()){
//            cout << i << " " << vec[i].size();
//            for(int j=0;j<vec[i].size();j++){
//                cout << " " << vec[i][j];
//            }
//            cout << endl;
//        }
//    }
}
