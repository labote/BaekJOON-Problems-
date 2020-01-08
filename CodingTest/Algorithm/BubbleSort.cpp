//
//  BubbleSort.cpp
//  Problems
//
//  Created by 홍민성 on 19/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> example;

void bubbleSort(int num){
    for(int i=0;i<num;i++){
        for(int j=0;j<num-1;j++){
            if(example[j]>example[j+1]){
                int temp;
                temp=example[j];
                example[j]=example[j+1];
                example[j+1]=temp;
            }
        }
    }
}

int main(){
    int num,k;
    cin >> num;
    
    for(int i=0;i<num;i++){
        cin >> k;
        example.push_back(k);
    }
    
    bubbleSort(num);
    
    for(int i=0;i<num;i++){
        cout << example[i] << " ";
    }
    cout << endl;
}
