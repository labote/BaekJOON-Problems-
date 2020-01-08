//
//  Problem1094.cpp
//  Problems
//
//  Created by 홍민성 on 08/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int X=64;
int ans;
int cnt;

int main(){
    int num;
    cin >> num;
    
    while(num!=ans){
        ans+=X;
        if(num<ans){
            ans-=X;
            X/=2;
        }
        else if(num==ans){
            cnt++;
            break;
        }
        else{
            cnt++;
            X/=2;
        }
    }
    
    cout << cnt << endl;
}
