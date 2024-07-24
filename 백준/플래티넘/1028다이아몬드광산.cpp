#include <iostream>

using namespace std;


int graph[750][750]={0,};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r,c;

    cin >> r >> c;
    for(int i=0 ; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> graph[i][j];
        }
    }
    for(int i=0 ; i<r; i++){
        for(int j=0; j<c; j++){
            cout <<graph[i][j];
        }
        cout<<'\n';
    }


    return 0;
}