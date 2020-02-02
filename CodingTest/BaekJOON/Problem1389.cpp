//
//  Problem1389.cpp
//  Problems
//
//  Created by 홍민성 on 15/10/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

//#include <iostream>
//#include <queue>
//#define MAX 101
//#define visited true
//#define Non_visited false
//
//using namespace std;
//
//vector<int> vec[MAX];
//vector<int> ans;
//bool check[MAX];
//int cnt[MAX];
//int M,N,key;
//
//void bfs(int start){
//    queue<int> q;
//    q.push(start);
//    check[start]=visited;
//
//    while(!q.empty()){
//        int x=q.front();
//        q.pop();
//
//        for(int i=0;i<vec[x].size();i++){
//            int nx=vec[x][i];
//            if(check[nx]!=visited){
//                cnt[nx]=cnt[x]+1;
//                q.push(nx);
//                check[nx]=visited;
//            }
//        }
//    }
//
//    int k=0;
//
//    for(int i=1;i<=M;i++){
//        k+=cnt[i];
//    }
////    cout << k << endl;
//    ans.push_back(k);
//}
//
//void Clear(){
//    for(int i=1;i<=M;i++){
//        check[i]=Non_visited;
//        cnt[i]=0;
//    }
//}
//
//int main(){
//
//    cin >> M >>N;
//
//    for(int i=0;i<M;i++){
//        int x,y;
//        cin >> x >> y;
//        vec[x].push_back(y);
//        vec[y].push_back(x);
//    }
//    for(int i=1;i<=M;i++){
//        bfs(i);
//        Clear();
//    }
//
//    int k=ans[0];
//
//    for(int i=1;i<ans.size();i++){
//        if(k>ans[i]){
//            k=ans[i];
//            key=i;
//        }
//    }
//    cout << key + 1 << endl;
//}

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define visited true
#define Non_visited false

using namespace std;

vector<int> num[MAX];
int N,M;
bool check[MAX];
int cnt[MAX];
int sum[MAX];

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start]=visited;
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        
        for(int i=0;i<num[x].size();i++){
            int nx=num[x][i];
            
            if(check[nx]!=visited){
                q.push(nx);
                cnt[nx]=cnt[x]+1;
                check[nx]=visited;
            }
        }
    }
    
    for(int i=1;i<=M;i++){
        sum[start]+=cnt[i];
    }
}

void clear(){
    for(int i=1;i<=M;i++){
        cnt[i]=0;
        check[i]=Non_visited;
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        num[a].push_back(b);
        num[b].push_back(a);
    }
    
    for(int i=1;i<=N;i++){
        bfs(i);
        clear();
    }

    int ans=1;
    int k=sum[1];
    
    for(int i=2;i<=N;i++){
        if(k>sum[i]){
            k=sum[i];
            ans=i;
        }
    }
    cout << ans << endl;
}
