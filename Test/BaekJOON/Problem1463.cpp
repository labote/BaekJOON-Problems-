//
//  Problem1463.cpp
//  Problems
//
//  Created by 홍민성 on 18/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int f[1000000];

int make(int num){
    
    if(num==1) return 0;
    if(num==2) return 1;
    if(num==3) return 1;
    if(f[num]!=0) return f[num];
    
//    for(int i=4;i<=num;i++){
//        f[i]=min(f[i],f[i-1]+1);
//        if(num%2==0){
//            f[i]=min(make(i),make(i/));
//        }
//        if(num%3==0){
//            f[i]=min(f[i], f[i/3]+1);
//        }
//    }
    
    f[num]=make(num-1)+1;
    
    if(num%2==0){
        f[num]=min(make(num),make(num/2)+1);
    }
    if(num%3==0){
        f[num]=min(make(num),make(num/3)+1);
    }
    
    return f[num];
}
int main(){
    int num;
    cin >> num;
    
    cout << make(num) << endl;
}
