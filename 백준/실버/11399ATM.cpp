#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
n명이 줄서있고, pi 분 씩걸린다.


*/

vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    int sum = 0;
    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++){
        cin >> x;
        v[i]= x;
    }
    sort(v.begin(), v.end());
    
    for(int i =0; i<n; i++){
        //cout <<v[i];
        sum += v[i]*(n-i);
    }

    cout << sum;
}