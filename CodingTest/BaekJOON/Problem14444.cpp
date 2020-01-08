//
//  Problem14444.cpp
//  Problems
//
//  Created by 홍민성 on 09/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#define MAX 100001*2

using namespace std;

int A[MAX];

void manachers(string S, unsigned long N)
{
    int r = 0, p = 0; // 0,0 으로 초기화
    for (int i = 0; i < N; i++)
    {
        if (i <= r) // 동작 원리 3-1번. i가 r보다 작거나 같으면 A[i]의 초기값은 min(r-i,A[i']), 이때 i'=2p-i
            A[i] = min(A[2 * p - i], r - i);
        // 여기서 질문, A[i']의 값을 가지고 왔을때, 어떻게 A[i]의 양옆이 팰린드롬인지 알 수 있는가?
        else // 동작 원리 3-2번. i>r이면 A[i]의 초기값 0
            A[i] = 0;
        
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
            // 동작 원리 4번. i를 중심으로 양쪽 문자열이 같을때까지만 반지름을 증가시킨다
            A[i]++;
        
        if (r < i + A[i]) // 동작 원리 2번. r=max(j+A[j]), 그떄의 j는 p이다.
        {
            r = i + A[i];
            p = i;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int length=0;
    string str,tmp;
    cin >> str;
    
    for(int i=0;i<str.size();i++){
        tmp+='#';
        tmp+=str[i];
    }

    tmp+='#';
    
    manachers(tmp,tmp.size());
//
//    for(int i=0;i<tmp.size();i++){
//        if(A[i]!=0){
//            cout << A[i];
//        }
//    }cout<< endl;
    
    for(int i=0;i<tmp.size();i++){
        length=max(length,A[i]);
    }
    cout << length << '\n';
}
