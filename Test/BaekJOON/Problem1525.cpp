//
//  Problem1525.cpp
//  Problems
//
//  Created by 홍민성 on 19/08/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

typedef pair<string,int> pir;

char iArr[3][3];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
string answer="123456780";
string number;
set<string> str;

int bfs(){
    queue<pir> q;
    q.push(pir(number,0));
    str.insert(number);
    
    while(!q.empty()){
        string first=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(first==answer){
            return cnt;
        }
        unsigned long index=first.find('0');
        unsigned long x=index/3;
        unsigned long y=index%3;
        
        for(int i=0;i<4;i++){
            unsigned long nx=x+xx[i];
            unsigned long ny=y+yy[i];
            
            if(nx<0 || ny<0 || nx>=3 || ny>=3) continue;
            string nstr=first;
            swap(nstr[3*x+y],nstr[3*nx+ny]);
            
            //find, nstr가 없다면 end()와 같은 iterator를 반환하기 때문에 str에 nstr이 있는지 없는지 확인하기 위해 find함수 사용
            if(str.find(nstr)==str.end()){
                str.insert(nstr);
                q.push(pir(nstr,cnt+1));
            }
        }
    }
    return -1;
}

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char num;
            cin >> num;
            iArr[i][j]=num;
            number+=iArr[i][j];
        }
    }
    
    cout << bfs() << endl;
}
