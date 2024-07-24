#include <iostream>

using namespace std;

int board[500][500];
int visited[500][500];
int max = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n,m;
    cin >> n >> m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> board[i][j];
        }
    }


}