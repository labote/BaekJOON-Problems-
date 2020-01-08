//
//  Problem4358.cpp
//  Problems
//
//  Created by 홍민성 on 27/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<string, double> m;
int cnt;

int main(){
    string str;
    
    while(getline(cin,str)){
        if(str.length()==0) break;
        cnt++;
        m[str]++;
    }
    
    cout << fixed;
    cout.precision(4);
    
    for(auto i : m){
        cout << i.first << " " << (i.second/cnt)*100 << endl;
    }
    
}
