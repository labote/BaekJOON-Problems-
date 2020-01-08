//
//  Problem1427.cpp
//  Problems
//
//  Created by 홍민성 on 12/11/2019.
//  Copyright © 2019 홍민성. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[10];

void counting(int num){

    while(num%10!=0 || num/10!=0){
        arr[num%10]++;
        num=num/10;
    }

    for(int i=9;i>=0;i--){
        while(arr[i]!=0){
            cout << i;
            arr[i]--;
        }
    }
}

int main(){
    int num;
    cin >> num;

    counting(num);
}


//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//
//int main(void)
//{
//    char numbers[10];
//    cin >> numbers;
//    sort(numbers, numbers + 10);
//    reverse(numbers, numbers + 10);
//    int i = 0;
//    while(numbers[i]!='\0')
//    {
//        cout << numbers[i] ;
//        i++;
//    }
//    return 0;
//}
