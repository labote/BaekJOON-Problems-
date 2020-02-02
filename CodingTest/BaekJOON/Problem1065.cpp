//
//  Problem1065.cpp
//  Problems
//
//  Created by 홍민성 on 2020/01/24.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int ans;

void find(){
    if(N<100){
        cout << N << endl;
    }
    else{
        
        for(int i=100;i<=N;i++){
            int hundreds=i/100;
            int tens=(i/10)-(hundreds*10);
            int units=i-(tens*10)-(hundreds*100);
            
            if((hundreds+units)/2==tens && (hundreds+units)%2==0){
                ans++;
            }
        }
        cout << ans + 99 << endl;
    }
}

int main(){
    cin >> N;
    
    find();
}
