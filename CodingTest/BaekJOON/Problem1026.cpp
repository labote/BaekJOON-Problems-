//
//  Problem1026.cpp
//  Problems
//
//  Created by 홍민성 on 12/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#define visited true
#define Non_visited false

using namespace std;

queue<int> idx;
int ans;

void Check(bool *check, int *arry2, int num){
    int temp;
    int val;

    for(int i=0;i<num;i++){
        temp=i;
        val=arry2[i];
        
        if(check[temp]==visited){
            val=-1;
            temp=-1;
        }
        
        for(int j=0;j<num;j++){
            if(check[j]==visited) continue;
            if(val<=arry2[j]){
                val=arry2[j];
                temp=j;
            }
        }
        idx.push(temp);
        check[temp]=visited;
    }
}


int main(){
    int num,j=0;
    cin >> num;

    int *arry=new int[num];
    int *arry2=new int[num];
    bool *check=new bool[num];

    for(int i=0;i<num;i++){
        cin >> arry[i];
    }

    for(int i=0;i<num;i++){
        check[i]=Non_visited;
    }

    for(int i=0;i<num;i++){
        cin >> arry2[i];
    }
    
    sort(arry,arry+num);

    Check(check, arry2, num);

    while(!idx.empty()){
        int i=idx.front();
        idx.pop();
        
        ans+=arry[j++]*arry2[i];
    }
    
    cout << ans << endl;

    delete[] arry;
    delete[] arry2;
    delete[] check;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int ans;
//
//int main(){
//    int num;
//    cin >> num;
//
//    int *arry=new int[num];
//    int *arry2=new int[num];
//
//    for(int i=0;i<num;i++){
//        cin >> arry[i];
//    }
//
//    for(int i=0;i<num;i++){
//        cin >> arry2[i];
//    }
//
//    sort(arry,arry+num);
//    sort(arry2,arry2+num,greater<int>());
//
//    for(int i=0;i<num;i++){
//        ans+=arry[i]*arry2[i];
//    }
//
//    cout << ans << endl;
//
//    delete[] arry;
//    delete[] arry2;
//}
