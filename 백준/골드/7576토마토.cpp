#include <iostream>
#include <queue>
using namespace std;
/*
m*n 짜리 상자 칸에 토마토 보관

익은 토마토 인접한 토마토는 영향을 받음
동서남북만

혼자 익진 않음
몇일 후에 다 익나

1 익음
0 안익음
-1 없음

*/
int graph[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> visited;

void bfs(int N, int M){
    
    while(!visited.empty()){
        int xx = visited.front().first;
        int yy = visited.front().second;

        visited.pop();

        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >=0 && ny>=0 && nx < N && ny < M){
                if(graph[nx][ny] == 0){
                    graph[nx][ny] = graph[xx][yy] + 1;
                    visited.push({nx, ny});
                }
            }
        }
       
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    int x;
    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> x;
            graph[i][j] = x;
            if(x==1) visited.push({i,j});
        }  
    }
    bfs(n,m);
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==0){
                cout << -1;
                return 0;
            }
            if(result<graph[i][j]) result = graph[i][j];
        }
    }
    cout << result-1;
    return 0;

}