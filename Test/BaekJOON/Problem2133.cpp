//
//  Problem2133.cpp
//  Problems
//
//  Created by 홍민성 on 23/09/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int arry[1001];

int dp(int n) {
    //D(n) = 3D(n-2) + 2{D(n-4)+D(n-6)+.....+D(0)}
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;
    if (arry[n] != 0) return arry[n];
    int sum = 3 * dp(n - 2);
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0) {
            sum += 2 * dp(n - i);
        }
    }
    return arry[n] = sum; // 오버플로우 방지하기 위해 나눠줌
    //값이 크기 때문에 결과값이 10007보다 크지 않도록 바꿔줌
}

int main() {
    int answer;
    
    cin >> answer;
    
    cout << dp(answer) << endl;
}
