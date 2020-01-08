//
//  Test(공백제거).cpp
//  Problems
//
//  Created by 홍민성 on 20/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

#define REMOVE_SPACES(x) x.erase(std::remove(x.begin(), x.end(), ' '), x.end())

using namespace std;

int main(){
    string s;
    cin >> s;
    s.erase(std::unique(s.begin(),s.end(),[](char s,char f){return (f==' '||s==' ');}),s.end());
    
    cout << s << endl;
}
