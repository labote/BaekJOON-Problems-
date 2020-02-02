//
//  Problem11403.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

//#include <iostream>
//#include <queue>
//#define MAX 101
//#define INF 987654321
//
//using namespace std;
//
//int map[MAX];
//int graph[MAX][MAX];
//int N;
//
//void floydWarhsall(){
//    int map[N][N];
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            map[i][j]=graph[i][j];
//        }
//    }
//
//    //k는 거쳐가는 노드
//    for(int k=0;k<N;k++){
//        //i는 출발 노드
//        for(int i=0;i<N;i++){
//            //j는 도착 노드
//            for(int j=0;j<N;j++){
//                if(map[i][k]+map[k][j] < map[i][j]){
//                    map[i][j]=map[i][k]+map[k][j];
//                }
//            }
//        }
//    }
//
//    //결과를 출력
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            if(map[i][j]==INF){
//                cout << "0" << " ";
//            }
//            else{
//                cout << "1" << " ";
//            }
//        }
//        cout << endl;
//    }
//}
//
//int main(){
//    cin >> N;
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cin >> graph[i][j];
//            if(graph[i][j]==0){
//                graph[i][j]=INF;
//            }
//        }
//    }
//    floydWarhsall();
//}

#include <iostream>
#include <queue>
#define MAX 101
#define INF 987654321

using namespace std;

int map[MAX];
int graph[MAX][MAX];
int N;

void bfs(){
    
}

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> graph[i][j];
        }
    }
}
