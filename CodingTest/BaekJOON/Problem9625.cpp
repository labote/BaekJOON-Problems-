//
//  Problem9625.cpp
//  Problems
//
//  Created by 홍민성 on 10/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 46

using namespace std;

int A[MAX];
int B[MAX];

int numberA(int x){
    if(x==-1) return 0;
    if(x==0) return 1;
    if(x==1) return 0;
    if(x==2) return 1;
    if(A[x]!=0) return A[x];
    return A[x] = numberA(x-1) + numberA(x-2);
}

int numberB(int x){
    if(x==-1) return 0;
    if(x==0) return 0;
    if(x==1) return 1;
    if(x==2) return 1;
    if(B[x]!=0) return B[x];
    return B[x] = numberB(x-1) + numberB(x-2);
}

using namespace std;

int main(){
    int ip;
    cin >> ip;
    
    cout << numberA(ip) << " " << numberB(ip) << endl;
}
