//
//  Problem1991(2).cpp
//  Problems
//
//  Created by 홍민성 on 29/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    char root;
    Node *left;
    Node *right;
};

Node *Create(char root){
    Node *newNode = new Node();
    newNode->root=root;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

void preOrder(Node *start){
    if(start==NULL) return;
    cout << start->root;
    preOrder(start->left);
    preOrder(start->right);
} // 전위 순회, 루트노드를 우선 방문한 후에 left 방문하고 right방문
void inOrder(Node *start){
    if(start==NULL) return;
    inOrder(start->left);
    cout << start->root;
    inOrder(start->right);
} // 중위 순회, 루트노드를 방문하기 전에 left가 있으면 먼저 방문 후 right 방문
void postOrder(Node *start){
    if(start==NULL) return;
    postOrder(start->left);
    postOrder(start->right);
    cout << start->root;
} // 후회 순회, 루트노드를 방문하기 전에 left가 있으면 먼저 방문하고 right가 있으면 방문하고 그 다음에 루트 노드를 방문

int main(){
    int num;
    cin >> num;
    
    Node *node[27];
    char child[27][2];

    for(int i=0;i<num;i++){
        char root, left, right;
        cin >> root >> left >> right;
        child[i][0]=left;
        child[i][1]=right;
        node[i]=Create(root);
    }
    // i 인덱스(루트)를 기준으로 child배열에 왼쪽child, 오른쪽child 저장
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(child[i][0]==node[j]->root){
                node[i]->left=node[j]; // 둘이 같다는것은 i번째 root의 왼쪽 자식이 존재한다는 것이다. 그러므로 노드의 i인덱스가 가리키는 left, 즉 왼쪽 자식은 j번째 노드 값이다.
            }
            if(child[i][1]==node[j]->root){
                node[i]->right=node[j]; // 반대로 오른쪽 자식을 나타낸다.
            }
        }
    }
    preOrder(node[0]);
    cout << endl;
    inOrder(node[0]);
    cout << endl;
    postOrder(node[0]);
    cout << endl;
}

