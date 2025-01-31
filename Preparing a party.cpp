// LINK : https://vjudge.net/problem/Gym-481102B
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    long long x , min_diff = LLONG_MAX , max_diff = LLONG_MIN;
    cin >> x ;
    long long arr [x];
    for(int i = 0 ; i < x ; i++){
        cin >> arr[i] ;
    }
// 8 6 -1 3 0
    for(int i = 1 ; i < x ; i++){
        min_diff = min(min_diff , abs(arr[i]-arr[i-1]));
        max_diff = max(max_diff , abs(arr[i]-arr[i-1]));
    }
    cout << max_diff << " " << min_diff << endl;
}