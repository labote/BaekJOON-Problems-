//
//  Problem1377.cpp
//  Problems
//
//  Created by 홍민성 on 16/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pir;
vector<pir> a;
int N;
int ans;

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        int K;
        cin >> K;
        a.push_back(pir(K,i));
    }
    
    sort(a.begin(), a.end());
    
    for(int i=0;i<N;i++){
        ans=max(ans,a[i].second-i+1);
    }
    
    cout << ans << endl;
}
