//
//  KMP.cpp
//  Problems
//
//  Created by 홍민성 on 10/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern){ // 실패함수 구현. 찾고자하는 문자열을 활용해서 실패 테이블 작성, 접두사와 접미사의 최대길이 포함
    long int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j=0;
    for(int i=1;i<patternSize;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=table[j-1];
        }
        if(pattern[i]==pattern[j]){
            table[i]=++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    long int parentSize = parent.size();
    long int patternSize = pattern.size();
    int j=0;
    for(int i=0;i<parentSize;i++){
        while(j>0 && parent[i]!=pattern[j]){
            j=table[j-1];
        }
        if(j==patternSize-1){ // 모든 문자가 하나씩 매칭되는 경우 전체 문자열이 매칭이 된 것
            cout << i-patternSize+2 << "번 째에서 찾았습니다." << endl;
            j=table[j]; // j가 가리키는 위치만큼 점프하기 위해 j값 갱신, 갱신한 이후에도 모든 위치를 출력해야되기 떄문에 찾은뒤에도 그만큼 점프
        }else // 매칭만 이루어진 경우
            j++;
    }
}

int main(){
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    
    KMP(parent,pattern);
//    vector<int> table = makeTable(pattern);
//    for(int i=0;i<table.size();i++){
//        cout << table[i] << " ";
//    }
}
