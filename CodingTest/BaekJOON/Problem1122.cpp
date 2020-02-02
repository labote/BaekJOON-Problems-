//
//  Problem1122.cpp
//  Problems
//
//  Created by 홍민성 on 17/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<string,int> pir;

int A,B,K;
int size;
string str;
string ans;
map<string,bool> Map;

void bfs(){
    queue<pir> que;
    que.push(pir(str,0));
    
    while(!que.empty()){
        string sibal=que.front().first;
        int cnt=que.front().second;
        que.pop();
        
        if(sibal==ans){
            cout << cnt << endl;
            return;
        }
        
        for(int i=0;i<size;i++){
            if(sibal[i]=='0'){
                sibal[i]='1';
            }else{
                sibal[i]='0';
            }
            for(int j=i+1;j<size;j++){
                if(sibal[j]=='0'){
                    sibal[j]='1';
                }else{
                    sibal[j]='0';
                }
                for(int k=j+1;k<size;k++){
                    if(sibal[k]=='0'){
                        sibal[k]='1';
                    }else{
                        sibal[k]='0';
                    }
                    if(!Map[sibal]){
                        que.push(pir(sibal,cnt+1));
                        Map[sibal]=true;
                    }
                    if(sibal[k]=='0'){
                        sibal[k]='1';
                    }else{
                        sibal[k]='0';
                    }
                }
                if(sibal[j]=='0'){
                    sibal[j]='1';
                }else{
                    sibal[j]='0';
                }
            }
            if(sibal[i]=='0'){
                sibal[i]='1';
            }else{
                sibal[i]='0';
            }
        }
    }
    
    cout << -1 << endl;
}

int main(){
    cin >> A >> B >> K;
    
    size=A+B;
    
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            str+='1';
        }
        str+='0';
    }
    
    for(int i=0;i<size;i++){
        ans+='1';
    }
    
    bfs();
}
