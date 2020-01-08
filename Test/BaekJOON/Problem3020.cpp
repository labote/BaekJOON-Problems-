//
//  Problem3020.cpp
//  Problems
//
//  Created by 홍민성 on 18/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bottom;
vector<int> top;
vector<long int> ans;

long int BS(int Key, long int start, long int end, vector<int> &list){
    
    long int mid;

    while(end-start>=0){
        mid=(start+end)/2;
        
        if(list[mid]>=Key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return end;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,H,num;
    cin >> N >> H;
    
    for(int i=0;i<N;i++){
        if(i%2==0){
            cin >> num;
            bottom.push_back(num);
        }
        else{
            cin >> num;
            top.push_back(H-num);
        }
    }
    
    sort(bottom.begin(),bottom.end());
    sort(top.begin(),top.end());
    
    long int bottomsize=bottom.size();
    long int topsize=top.size();
    
    long int M;
    int cnt=0;
    
    for(int i=1;i<=H;i++){
        M=bottomsize - BS(i, 0, bottomsize-1, bottom) + BS(i, 0, topsize-1, top);
        ans.push_back(M);
    }
    sort(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++){
        if(ans[0]!=ans[i]){
            break;
        }
        cnt++;
    }
    cout << ans[0] << " " << cnt << endl;
}
