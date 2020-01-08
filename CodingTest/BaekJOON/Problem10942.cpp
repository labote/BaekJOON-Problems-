//
//  Problem10942.cpp
//  Problems
//
//  Created by 홍민성 on 10/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 2001*2

using namespace std;

int A[MAX];
char num[MAX];
string tmp;
queue<int> number;

void manachers(string S, unsigned long N){
    int r = 0, p = 0; // 0,0 으로 초기화
    for (int i = 0; i < N; i++){
        if (i <= r) {
            A[i] = min(A[2 * p - i], r - i);// 동작 원리 3-1번. i가 r보다 작거나 같으면 A[i]의 초기값은 min(r-i,A[i']), 이때
        }
        // 여기서 질문, A[i']의 값을 가지고 왔을때, 어떻게 A[i]의 양옆이 팰린드롬인지 알 수 있는가?
        else
            A[i] = 0;// 동작 원리 3-2번. i>r이면 A[i]의 초기값 0
        
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
        // 동작 원리 4번. i를 중심으로 양쪽 문자열이 같을때까지만 반지름을 증가시킨다
        
        if (r < i + A[i]){  // 동작 원리 2번. r=max(j+A[j]), 그떄의 j는 p이다.
            r = i + A[i];
            p = i;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int M,N;
    cin >> M;
    
    for(int i=0;i<M;i++){
        char cha;
        cin >> cha;
        num[i]=cha;
    }
    
    for(int i=0;i<=M;i++){
        tmp+='#';
        tmp+=num[i];
    }
    tmp+='#';
    
    manachers(tmp, tmp.size());
    
    cin >> N;
    
    while(N--){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        x*=2;
        y*=2;
        
        int r=A[(x+y)/2];
        if((x+y)/2+r>=y){
            number.push(0);
        }else
            number.push(1);
//        if((x+y)/2+r>=y){
//            cout << "0" << '\n';
//        }else
//            cout << "1" << '\n';
    }
    while(!number.empty()){
        cout << number.front() << endl;
        number.pop();
    }

//    for(int i=0;i<N;i++){
//        int x,y;
//        cin >> x >> y;
//        q.push(make_pair(x-1,y-1));
//    }
//
//    while(!q.empty()){
//        int length=0;
//        int x=q.front().first;
//        int y=q.front().second;
//        int z=y-x+1;
//        q.pop();
//
//        tmp="";
//
//        for(int i=x;i<=y;i++){
//            tmp+='#';
//            tmp+=num[i];
//        }
//        tmp+='#';
//        manachers(tmp, tmp.size());
//
//        for(int i=0;i<tmp.size();i++){
//            length=max(length,A[i]);
//        }
//        //cout << length << " " << y-x+1 <<endl;
//        if(length==z){
//            cout << "1" << '\n';
//        }
//        else
//            cout << "0" << '\n';
//    }
//}
}
