//
//  Problem1991.cpp
//  Problems
//
//  Created by 홍민성 on 27/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

//struct Node{
//    char val;
//    Node *left;
//    Node *right;
//};

struct node{
    char left;
    char right;
};

struct node arr[100];

void preOrder(char root){
    if(root=='.') return;
    else{
        cout << root;
        preOrder(arr[root].left);
        preOrder(arr[root].right);
    }
}

void inOrder(char root){
    if(root=='.') return;
    else{
        inOrder(arr[root].left);
        cout << root;
        inOrder(arr[root].right);
    }
}

void postOrder(char root){
    if(root=='.') return;
    else{
        postOrder(arr[root].left);
        postOrder(arr[root].right);
        cout << root;
    }
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        char al,pa,bet;
        cin >> al >> pa >> bet;
        arr[al].left=pa;
        arr[al].right=bet;
    }
    preOrder('A');
    cout << endl;
    inOrder('A');
    cout << endl;
    postOrder('A');
    cout << endl;
}
