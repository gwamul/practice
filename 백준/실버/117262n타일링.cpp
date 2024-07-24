#include <iostream>
#include <vector>
using namespace std;
/*
2*n을 직사각형 1*2 2*1 타일로 채우기



*/



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp;

    dp.push_back(1);
    dp.push_back(2);
    for(int i = 2; i<n; i++){
        dp.push_back((dp[i-1]+dp[i-2])%10007);

    }
    cout << dp[n-1];
    
}