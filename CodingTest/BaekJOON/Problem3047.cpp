//
//  Problem2644.cpp
//  Problems
//
//  Created by 홍민성 on 11/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> abc;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    
    string str;
    cin >> str;
    
    abc.push_back(a);
    abc.push_back(b);
    abc.push_back(c);
    
    sort(abc.begin(),abc.end());
    
    for(int i=0;i<3;i++){
        char Alpha = str[i];
        
        switch (Alpha) {
            case 'A':
                cout << abc[0];
                break;
            case 'B' :
                cout << abc[1];
                break;
            case 'C' :
                cout << abc[2];
                break;
            default:
                break;
        }
        cout << " ";
    }
}
