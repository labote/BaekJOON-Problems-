//
//  Problem1963.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 10001
#define visited true
#define Non_visited false

using namespace std;

int iArr[MAX];
bool bArr[MAX];
bool Check[MAX];

void eratosthenes(int aNumber, int bNumber){
    if(aNumber==1){
        aNumber++;
    }
    for(int i=2;i<=bNumber;i++){
        if(bArr[i]){
            continue;
        }
        for(int j=i*i;j<=bNumber;j+=i){
            bArr[j]=visited;
        }
    }
    for(int i=aNumber;i<=bNumber;i++){
        if(!bArr[i]){
            iArr[i]=i;
        }
    }
}

int bfs(int aNumber, int bNumber){
    memset(Check,Non_visited,sizeof(Check));
    
    queue<pair<int,int>> q;
    q.push(make_pair(aNumber,0));
    
    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        int dx[4]={x/1000,(x/100)%10,(x/10)%10,x%10};
        
        if(Check[x]) continue;
        if(x==bNumber) return cnt;
        
        Check[x]=visited;

        //1.각 자리 수 10넘어가는거
        //2.두 번 카운터 되는거 ex)1033,1433 -> 1733 이때 2번 체크됌
        for(int i=0;i<4;i++){ // 각 자리수 체크
            for(int j=0;j<10;j++){ // 각 자리수 *j
                int nx=0;
                for(int k=0;k<4;k++){
                    if(i==k){ // i자리수만 바꿈
                        nx+=j*pow(10,3-k);
                    }
                    else
                        nx+=dx[k]*pow(10,3-k);
                }
                if(10000<=nx || nx<1000 || Check[nx]==visited || iArr[nx]==0)continue;
                q.push(make_pair(nx,cnt+1));
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    queue<pair<int,int>> q;
    
    
    //arr.assign(N, vector<int>(2, 0)); 신기방기 -> arr[i].push_back(number); 했을때 값이 안들어감 --> 이유는 뭘까? arr[i][j]=number로 할 경우 들어감
    
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        q.push(make_pair(x,y));
    }
    
    eratosthenes(1000,9999);
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int cnt=bfs(x,y);
        if(cnt==-1){
            cout << "Impossible" << endl;
        }else
            cout << cnt << endl;
    }
}
