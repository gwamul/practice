#include <iostream>
#include <cstring>


using namespace std;
/*
rgb 동서남북으로 이어진걸 구역이라고 하고

일반인과 적록색맹이 
구분할 수 있는 구역의 갯수 각각 구하기


*/

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int visited[101][101] = {0};



char graph[101][101];

int N;


void dfs(int x, int y){
    if(visited[x][y] == 1) return;
    visited[x][y] = 1;

    for(int i=0; i<4; i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;

        if((graph[x][y] == graph[nx][ny]) && visited[nx][ny]==0){
            dfs(nx,ny);
        }

    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt=0;
 
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    
    cout <<cnt<<" ";
    cnt =0;
    memset(visited,0, sizeof(visited));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] == 'G') graph[i][j] = 'R';
        }
    }
    for(int i=0; i<N; i++){
        
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                dfs(i,j);
                cnt++;
            }
        }
        
    }
  
    cout <<cnt;
    return 0;

}