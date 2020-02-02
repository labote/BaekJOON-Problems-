//
//  Problem10814.cpp
//  Problems
//
//  Created by 홍민성 on 16/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct mem{
    int age;
    string name;
    int order;
};

vector<mem> vec;
vector<mem> sorted;

void Merge(int start, int mid, int end){
    int i=start;
    int j=mid+1;
    int k=start;
    int l;
    
    while(i<=mid && j<=end){
        if(vec[i].age>vec[j].age){
            sorted[k++]=vec[j++];
        }
        else if(vec[i].age==vec[j].age){
            if(vec[i].order>vec[j].order){
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
    
    if(i>mid){
        for(l=j;l<=end;l++){
            sorted[k++]=vec[l];
        }
    }else{
        for(l=i;l<=mid;l++){
            sorted[k++]=vec[l];
        }
    }
    
    for(int l=start;l<=end;l++){
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

    int N;
    cin >> N;
    
    mem member;
    
    for(int i=0;i<N;i++){
        cin >> member.age >> member.name;
        member.order=i;
        vec.push_back(member);
    }
    
    sorted=vector<mem> (N);
    
    MergeSort(0,N-1);
    
    for(int i=0;i<N;i++){
        cout << vec[i].age << " " << vec[i].name << '\n';
    }
}
