#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
/*
비밀번호



*/
unordered_map<string, string> map;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    string url, pw;
    
    for(int i =0; i<n; i++){
        cin >> url >> pw;
        map.insert({url, pw});
    }

    for(int i=0; i<m; i++){
        cin >> url;
        cout << map[url] << endl;
    }
}