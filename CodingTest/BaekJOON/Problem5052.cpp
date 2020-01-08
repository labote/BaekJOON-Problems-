//
//  Problem5052.cpp
//  Problems
//
//  Created by 홍민성 on 06/12/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

//////////////////////////////////////////////////////
// 길이로

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//vector<string> answer;
//
//void check(vector<string> &list, int n){
//
//    for(int i=0;i<n-1;i++){
//        long int firstSize=list[i].size();
//        long int secondSize=list[i+1].size();
//
//        if(firstSize<secondSize){
//            if(list[i]==list[i+1].substr(0,firstSize)){
//                answer.push_back("NO");
//                return;
//            }
//        }
//    }
//    answer.push_back("YES");
//}
//
//int main(){
//    int t;
//    cin >> t;
//
//    for(int i=0;i<t;i++){
//        int n;
//        cin >> n;
//
//        vector<string> str(n);
//
//        for(int j=0;j<n;j++){
//            cin >> str[j];
//        }
//
//        sort(str.begin(),str.end());
//
//        check(str,n);
//    }
//
//    for(int i=0;i<answer.size();i++){
//        cout << answer[i] << '\n';
//    }
//}
//

///////////////////////////////////////////////
//     Trie

#include <iostream>
#include <vector>

using namespace std;

vector<string> answer;

struct Phone{
    char num[10];
};

struct Trie{
    bool finish;
    Trie* next[10];
    Trie(): finish(false) {
//        fill(next, next+10, 0);
        for(int i=0;i<10;i++){
            next[i]=0;
        }
    }

    ~Trie() {
        for(int i=0;i<10;i++){
            if(next[i]){
                delete next[i];
            }
        }
    }
    void insert(const char* key){
        if(*key=='\0'){
            finish=true;
        }else{
            int curr=*key-'0';
            if(next[curr]==NULL){
                next[curr]=new Trie();
            }
            next[curr]->insert(key+1);
        }
    }
    bool find(const char* key){
        if(*key=='\0') return false;
        if(finish) return true;
        int curr=*key-'0';
        return next[curr]->find(key+1);
    }
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        Phone number[10001]={0,};

        for(int i=0;i<n;i++){
            cin >> number[i].num;
        }

        int flag=0;
        Trie *root = new Trie();

        for(int i=0;i<n;i++){
            root->insert(number[i].num);
        }

        for(int i=0;i<n;i++){
            if(root->find(number[i].num)){
                flag=1;
                break;
            }
        }
        if(flag) answer.push_back("NO");
        else answer.push_back("YES");
    }

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }

}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<string> answer;
//
//struct Phone{
//    char number[10];
//};
//
//struct Trie{
//    Trie *next[10];
//    bool finish;
//    bool nextChild;
//
//    Trie(){
//        fill(next,next+10,nullptr);
//        finish=nextChild=false;
//    }
//
//    ~Trie(){
//        for(int i=0;i<10;i++){
//            if(next[i]){
//                delete next[i];
//            }
//        }
//    }
//    bool insert(const char *key){
//        if(*key=='\0'){
//            finish=true;
//
//            if(nextChild){
//                return 0;
//            }else{
//                return 1;
//            }
//        }
//
//        int nextKey=*key-'0';
//
//        if(!next[nextKey]){
//            next[nextKey]=new Trie;
//        }
//        nextChild=true;
//
//        bool get=next[nextKey]->insert(key+1);
//
//        return !finish && get;
//    }
//};
//
//int main(){
//    int t;
//    cin >> t;
//
//    while(t--){
//        int n;
//        cin >> n;
//
//        Trie *root = new Trie();
//        Phone phone[10001]={0,};
//        bool chk=true;
//
//        for(int i=0;i<n;i++){
//            cin >> phone[i].number;
//
//            if(chk && root->insert(phone[i].number)==0){
//                chk=false;
//            }
//        }
//
//        if(chk)
//            answer.push_back("YES");
//        else
//            answer.push_back("NO");
//
//        delete root;
//    }
//
//    for(int i=0;i<answer.size();i++){
//        cout << answer[i] << '\n';
//    }
//
//}
//
