//
//  Problem14425.cpp
//  Problems
//
//  Created by 홍민성 on 17/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<string> Nstr;
//vector<long int> Norder;
//vector<string> Mstr;
//vector<long int> Morder;
//int N,M;
//int ans;
//
//void compareWords(int i,int j){
//    if(Nstr[i]==Mstr[j]){
//        ans++;
//    }
//}
//
//void compareSize(){
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            if(Norder[i]==Morder[j]){
//                compareWords(i,j);
//            }
//        }
//    }
//}
//
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    cin >> N >> M;
//    for(int i=0;i<N;i++){
//        string str;
//        cin >> str;
//        Nstr.push_back(str);
//
//        long int size=str.size();
//        Norder.push_back(size);
//    }
//
//    for(int i=0;i<M;i++){
//        string str;
//        cin >> str;
//        Mstr.push_back(str);
//
//        long int size=str.size();
//        Morder.push_back(size);
//    }
//
//    compareSize();
//
//    cout << ans << '\n';
//}

#include <iostream>
#include <map>
#define MAX 10001

using namespace std;

map<string,int> Map;
string str[MAX];
int N,M;
int ans;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string Nstr;
        cin >> Nstr;
        Map[Nstr]=1;
    }
    for(int i=0;i<M;i++){
        cin >> str[i];
    }
    
    for(int i=0;i<M;i++){
        if(Map[str[i]]){
            ans++;
        }
    }
    
    cout << ans << endl;
}
