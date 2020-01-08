//
//  Problem1786.cpp
//  Problems
//
//  Created by 홍민성 on 30/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int cnt;
vector<long int> ans;

vector<int> maketable(string pattern){
    long int size=pattern.size();
    vector<int> table(size,0);
    int j=0;
    for(int i=1;i<size;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=table[j-1];
        }
        if(pattern[i]==pattern[j]){
            table[i]=++j; // table[i]=j+1; j++; 이 두 개를 한번에
        }
    }
    return table;
}

void KMP(string parent, string pattern){
    //시간 복잡도 : O(N)
    vector<int> table=maketable(pattern);
    long int parentSize=parent.size();
    long int patternSize=pattern.size();
    int j=0;
    for(int i=0;i<parentSize;i++){
        while(j>0 && parent[i]!=pattern[j]){
            j=table[j-1];
        }
        if(parent[i]==pattern[j]){
            if(j==patternSize-1){
                cnt++;
                ans.push_back(i-patternSize+2);
                //cout << i-patternSize+2;
                j=table[j]; // 매칭이 이루어지는 모든 위치를 다 출력하기 위해 그만큼 점프시킴
            }else{
                j++;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    string parent,pattern;
    getline(cin,parent);
    getline(cin,pattern);

    KMP(parent, pattern);
    
    cout << cnt << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }
}
