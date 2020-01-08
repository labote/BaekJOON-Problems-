////
////  Problem6603.cpp
////  Problems
////
////  Created by 홍민성 on 11/08/2019.
////  Copyright © 2019 홍민성. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#define visited true
//#define Non_visited false
//using namespace std;
//
//vector<int> lotto;
//vector<bool> Check;
//
//int cnt;
//
//void Lotto(int n, int step){
//    if(cnt==6){
//        int k=0;
//        for(int i=0; i<n; i++){
//            if(Check[i]==visited){
//                k++;
//            }
//        }
//        if(k==6){
//            for(int i=0; i<n; i++){
//                if(Check[i]==visited){
//                    cout << lotto[i] << " ";
//                }
//            }
//            cout << endl;
//        }
//        step--;
//        return;
//    }
//
//    for(int i=step; i<n; i++){
//        Check[i]=visited;
//        cnt+=1;
//        Lotto(n, step+1);
//        cnt-=1;
//        Check[i]=Non_visited;
//    }
//}
//
//int main(){
//    bool root = true;
//
//    while(root){
//        int k;
//        cin>>k;
//        if(k==0){
//            root=false;
//        }
//        for(int i=0; i<k; i++){
//            int num;
//            cin >> num;
//            lotto.push_back(num);
//            Check.push_back(Non_visited);
//        }
//        Lotto(k,0);
//    }
////    for(int i=0; i<k; i++){
////        cout << lotto[i] << " ";
////    }
////
////    for(int i=0; i<k; i++){
////        cout << Check[i] << " ";
////    }
////    Check[0] = visited;
////    for(int i=0; i<k; i++){
////        cout << Check[i] << " ";
////    }
//
//
////   Lotto(k,0);
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#define visited true
//#define Non_visited false
//
//using namespace std;
//
//queue<int> lotto;
//queue<int> lottoN;
//vector<bool> Check;
//vector<int> store;
//int cnt;

//void Lotto(int M, int step){
//    int k=0;
//
//    if(cnt==6){
//        for(int i=0;i<M;i++){
//            if(Check[i]==visited){
//                k++;
//            }
//        }
//        if(k==6){
//            for(int i=0;i<M;i++){
//                if(Check[i]==visited){
//                    cout << store[i] << " ";
//                }
//            }
//            cout << endl;
//        }
//        step-=1;
//        return;
//    }
//
//    for(int i=step; i<M; i++){
//        Check[i]=visited;
//        cnt+=1;
//        Lotto(M,step+1);
//        cnt-=1;
//        Check[i]=Non_visited;
//    }
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#define visited true
//#define Non_visited false
//
//using namespace std;
//
//queue<int> lotto;
//queue<int> lottoN;
//vector<bool> Check;
//vector<int> store;
//
//// 함수 순서
//bool isPossible(int M, int step, int cnt){
//    if(cnt>6 && cnt<0){
//        return false;
//    }
//    if(6-cnt>M-step){
//        return false;
//    }
//    return true;
////    if(cnt>6 && cnt <0){
////        return false;
////    }
////    if(6-cnt>=M-step){
////        return false;
////    }
////    return true;
//
//}
//
//void Lotto(int M, int step, int cnt){ // step = index
////    if(cnt==6){
////        for(int i=0; i<6; i++){
////            cout << store2[i];
////        }
////        cout << endl;
////        return;
////    }
//    if(cnt==6){
//        for(int i=0; i<6; i++){
//            if(Check[i]==visited){
//                cout << store[i];
//            }
//
//        }
//        cout << endl;
//        return;
//
//    }
////    for(int i=step; i<M; i++){
////
////        if(isPossible(i,step,cnt)){
////            Check[i]=visited;
////            Lotto(M,step+1,cnt+1);
////            Check[i]=Non_visited;
////        }
////        else{
////            Lotto(M,step+1,cnt);
////        }
////    }
//    Check[step]=visited;
//    Lotto(M,step+1,cnt+1);
//
//    Check[step]=Non_visited;
//    Lotto(M,step+1,cnt);
//
//}
//
//
//int main(){
//    bool key = true;
//
//    while(key){ // 첫번째 자리에 숫자 0을 입력하기 전까지 계속 숫자를 받는다.
//        int num, input;
//        cin >> num;
//        if(num==0){
//            break;
//        }
//
//        lottoN.push(num);
//
//        for(int i=0; i<num; i++){
//            cin>>input;
//            lotto.push(input);
//        }
//    }
////    int num = lottoN.front();
////    lottoN.pop();
////    for(int i=0; i<num;i++){
////        Check.push_back(Non_visited);
////    }
////    for(int i=0; i<num; i++){
////        store.push_back(lotto.front());
////        lotto.pop();
////    }
////    for(int i=0; i<num; i++){
////        cout << store[i] << " " << Check[i] << endl;
////    }
//
//    while(!lotto.empty()){ // 입력받은 데이터를 이용해 로또번호 수 계산, lotto 큐가 비어있지 않으면 계속 반복
//        int num = lottoN.front();
//        lottoN.pop();
//
//        store=vector<int> (num,0);
//        Check=vector<bool> (num,Non_visited);
//
//        for(int i=0; i<num; i++){
//            store[i]=lotto.front();
//            lotto.pop();
//        }
////        for(int i=0; i<num; i++){
////            Lotto(i,0);
////        }
//        Lotto(num,0,0);
//    }
//
//}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> lotto;
queue<int> lottoN;
vector<int> store;
int ans[6];

void Lotto(int num, int step, int cnt){
    
    if(cnt==6){
        for(int i=0;i<6;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }else{
        for(int i=step;i<num;i++){
//            if(isPossible()){
//                ans[step]=store[i];
//                Lotto(num,step+1,cnt+1);
//            }
//            else
//                Lotto(num,step+1,cnt);
//        }
            ans[cnt]=store[i];
            Lotto(num,i+1,cnt+1);
            ////////////// i+1 대신 step+1을 넣으면 안되는 이유?
        }
    }
}

int main(){
    bool key = true;
    
    while(key){ // 첫번째 자리에 숫자 0을 입력하기 전까지 계속 숫자를 받는다.
        int num, input;
        cin >> num;
        if(num==0){
            break;
        }
        
        lottoN.push(num);
        
        for(int i=0; i<num; i++){
            cin>>input;
            lotto.push(input);
        }
    }
    
    while(!lotto.empty()){ // 입력받은 데이터를 이용해 로또번호 수 계산, lotto 큐가 비어있지 않으면 계속 반복
        int num = lottoN.front();
        lottoN.pop();
        
        store=vector<int> (num,0);
        
        for(int i=0; i<num; i++){
            store[i]=lotto.front();
            lotto.pop();
        }
        Lotto(num,0,0);
        cout << endl;
    }
}
