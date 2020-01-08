//
//  Problem11651.cpp
//  Problems
//
//  Created by 홍민성 on 11/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pir;
vector<pir> vec;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int n,m;
    
    while(N--){
        cin >> n >> m;
        vec.push_back(pir(m,n));
    }
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i].second << " " << vec[i].first << '\n';
    }
}
