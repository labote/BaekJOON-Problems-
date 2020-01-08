//
//  Problem10825.cpp
//  Problems
//
//  Created by 홍민성 on 06/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct student{
    string name;
    int kor;
    int eng;
    int math;
};

vector<student> vec;
vector<student> sorted;

void Merge(int start, int mid, int end){
    int i,j,k,l;
    i=start;
    j=mid+1;
    k=start;
    
    while(i<=mid && j<=end){
        if(vec[i].kor==vec[j].kor && vec[i].eng==vec[j].eng && vec[i].math==vec[j].math){
            if(vec[i].name<vec[j].name){
                sorted[k++]=vec[i++];
            }
            else{
                sorted[k++]=vec[j++];
            }
        }
        else if(vec[i].kor==vec[j].kor && vec[i].eng==vec[j].eng){
            if(vec[i].math>vec[j].math){
                sorted[k++]=vec[i++];
            }
            else{
                sorted[k++]=vec[j++];
            }
        }
        else if(vec[i].kor==vec[j].kor){
            if(vec[i].eng<vec[j].eng){
                sorted[k++]=vec[i++];
            }
            else{
                sorted[k++]=vec[j++];
            }
        }
        else{
            if(vec[i].kor>vec[j].kor){
                sorted[k++]=vec[i++];
            }
            else{
                sorted[k++]=vec[j++];
            }
        }
    }
    
    if(i>mid){
        for(l=j;l<=end;l++){
            sorted[k++]=vec[l];
        }
    }
    else{
        for(l=i;l<=mid;l++){
            sorted[k++]=vec[l];
        }
    }
    
    for(l=start;l<=end;l++){
        vec[l]=sorted[l];
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int num;
    student sc;
    
    cin >> num;
    
    for(int i=0;i<num;i++){
        cin >> sc.name >> sc.kor >> sc.eng >> sc.math;
        vec.push_back(sc);
    }
    
    sorted = vector<student> (num);
    
    MergeSort(0,num-1);
    
    for(int i=0;i<num;i++){
        cout << vec[i].name << '\n';
        //cout << vec[i].name << endl;
    }
}
