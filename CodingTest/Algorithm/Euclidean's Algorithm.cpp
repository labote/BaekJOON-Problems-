//
//  Euclidean's Algorithm.cpp
//  Problems
//
//  Created by 홍민성 on 10/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int Euclidean(int M, int N){
    int remainder=0;
    
    remainder = N ? Euclidean(N,M%N) : M;
    
    return remainder;
}

int main(){
    int M,N;
    cin >> M >> N;
    
    cout << Euclidean(M,N) << endl;
    
}
