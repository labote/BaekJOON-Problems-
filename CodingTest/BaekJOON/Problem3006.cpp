//
//  Problem3006.cpp
//  Problems
//
//  Created by 홍민성 on 21/01/2020.
//  Copyright © 2020 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100002

using namespace std;

int main(){
    int val = 12;
    int first = (val&-val);
    
    cout << first << endl;
}


//#include <iostream>
//#include <algorithm>
//#define MAX 100002
//
//using namespace std;
//
//typedef pair<int,int> pir;
//
//pir vec[MAX];
//int map[MAX];
//int idx[MAX];
//int N,num;
//
//void tSort(){
//    int i=0;
//    int j=N-1;
//
//    while(i<j){
//
//        int firstIdx=vec[i].second;
//        int lastIdx=vec[j].second;
//
//        for(int l=0;l<firstIdx;l++){
//            idx[i]+=map[l];
//        }
//        map[firstIdx]=0;
//
//        printf("%d\n",idx[i]);
//
//        for(int l=lastIdx+1;l<N;l++){
//            idx[j]+=map[l];
//        }
//        map[lastIdx]=0;
//
//        printf("%d\n",idx[j]);
//
//        i++;
//        j--;
//    }
//    printf("%d\n",0);
//}
//
//int main(){
//
//    scanf("%d",&N);
//
//    for(int i=0;i<N;i++){
//        pir pi;
//        scanf("%d",&pi.first);
//        pi.second=i;
//        vec[i]=pi;
//        map[i]=1;
//    }
//
//    sort(vec,vec+N);
//
//    tSort();
//}

//#include <iostream>
//#include <algorithm>
//#define MAX 100002
//
//using namespace std;
//
//typedef pair<int,int> pir;
//
//pir vec[MAX];
//int map[MAX];
//int idx[MAX];
//int N,num;
//
//void tSort(){
//    int i=0;
//    int j=N-1;
//
//    while(i<j){
//
//        int firstIdx=vec[i].second;
//        int lastIdx=vec[j].second;
//
//        for(int l=0;l<firstIdx;l++){
//            idx[i]+=map[l];
//        }
//        map[firstIdx]=0;
//
//        cout << idx[i] << '\n';
//
//        for(int l=lastIdx+1;l<N;l++){
//            idx[j]+=map[l];
//        }
//        map[lastIdx]=0;
//
//        cout << idx[j] << '\n';
//
//        i++;
//        j--;
//    }
//    cout << 0 << endl;
//}
//
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    cin >> N;
//
//    for(int i=0;i<N;i++){
//        pir pi;
//        cin >> pi.first;
//        pi.second=i;
//        vec[i]=pi;
//        map[i]=1;
//    }
//
//    sort(vec,vec+N);
//
//    tSort();
//}

//void tSort(){
//    int i=0;
//    int j=N-1;
//
//    while(i<j){
//        int left=0;
//        int right=0;
//
//        for(int m=0;m<vec[i].second;m++){
//            left+=map[m];
//        }
//        map[vec[i].second]=0;
//
//        printf("%d\n",left);
////        ans.push_back(left);
////        cout << left << '\n';
//
//        for(int n=vec[j].second+1;n<N;n++){
//            right+=map[n];
//        }
//        map[vec[j].second]=0;
//
//        printf("%d\n",right);
////        ans.push_back(right);
////        cout << right << '\n';
//        i++;
//        j--;
//    }
//    cout << 0 << '\n';
//}
//int main(){
////    cin.tie(NULL);
////    ios_base::sync_with_stdio(false);
//
//    cin >> N;
//
//    for(int i=0;i<N;i++){
////        cin >> num;
//        scanf("%d",&vec[i].first);
//        vec[i].second=i;
//        map[i]=1;
////        vec.push_back(pir(num,i));
//    }
////    sort(vec.begin(),vec.end());
////
////    map=vector<int> (N,1);
//
//    sort(vec,vec+N);
//    tSort();
//
//}
