//
//  Problem1015.cpp
//  Problems
//
//  Created by 홍민성 on 16/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct order{
    int pi;
    int ai;
    int bi;
};

vector<order> vec;
int num;

bool compAi(const order &a, const order &b){
    if(a.ai != b.ai){
        if(a.ai < b.ai){
            return true;
        }
        else{
            return false;
        }
    }
    
    if(a.bi < b.bi){
        return true;
    }
    else{
        return false;
    }
}

bool compBi(const order &a, const order &b){
    if(a.bi < b.bi){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> num;
    
    order sequence;
    
    for(int i=0;i<num;i++){
        cin >> sequence.ai;
        sequence.bi=i;
        vec.push_back(sequence);
    }
    
    sort(vec.begin(),vec.end(),compAi);
    
    for(int i=0;i<num;i++){
        vec[i].pi=i;
    }
    
    sort(vec.begin(),vec.end(),compBi);
    
    for(int i=0;i<num;i++){
        cout << vec[i].pi << " ";
    }
    cout << '\n';
}
