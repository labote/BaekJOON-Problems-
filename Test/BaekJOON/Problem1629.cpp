//
//  Problem1629.cpp
//  Problems
//
//  Created by 홍민성 on 10/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

long long pow(int a, int b, int c){
    int ans;
    if(b==0) return 1;
    else if(b==1) return a%c;
    else if(b%2==0){
        long long temp = pow(a,b/2,c);
        ans = temp*temp % c ;
    }else{
        ans = a*pow(a,b-1,c)%c;
    }
    return ans;
}

int main(){
    int A,B,C;
    cin>> A >> B >> C;
    
    cout << pow(A,B,C) << endl;
}
