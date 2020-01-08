//
//  Problem1149.cpp
//  Problems
//
//  Created by 홍민성 on 01/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 1001

int RGB[MAX][3];

using namespace std;

int dp(int num){
    int ans;
    
    if(num==1) return ans=min({RGB[0][0],RGB[0][1],RGB[0][2]});
    
    for(int i=1;i<num;i++){
        RGB[i][0]=RGB[i][0]+min(RGB[i-1][1],RGB[i-1][2]);
        RGB[i][1]=RGB[i][1]+min(RGB[i-1][0],RGB[i-1][2]);
        RGB[i][2]=RGB[i][2]+min(RGB[i-1][0],RGB[i-1][1]);
    }
    
    return ans=min({RGB[num-1][0],RGB[num-1][1],RGB[num-1][2]});
}

int main(){
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++){
        for(int j=0;j<3;j++){
            int M;
            cin >> M;
            RGB[i][j]=M;
        }
    }
    cout << dp(num) << endl;
}
