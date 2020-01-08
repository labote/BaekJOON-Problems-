//
//  Problem1083.cpp
//  Problems
//
//  Created by 홍민성 on 14/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

void Sort(int N, int cnt){
    int k=min(cnt+1,N);
    int l=0,MAX=0,p=0;
    int temp;
    
    for(int m=0;m<N && cnt>0;m++){
        for(int i=l;i<k && k<=N;i++){ // 정해진 범위 내에서 최대값 찾기
            if(MAX<vec[i]){
                MAX=vec[i];
                p=i;
            }
        }
        for(int j=p;j>=l+1 && cnt>0;j--,cnt--){
            temp=MAX;
            vec[j]=vec[j-1];
            vec[j-1]=temp;
        }
        l++;
        k=min(cnt+l+1,N);
        MAX=0;
    }
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        int key;
        cin >> key;
        vec.push_back(key);
    }
    
    int cnt;
    cin >> cnt;
    
    Sort(num, cnt);
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
}
