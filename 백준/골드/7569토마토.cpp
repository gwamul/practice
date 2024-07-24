#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int m,n,h;
int graph[101][101][101];

int visited[101][101][101] = {0,};

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
queue<pair<pair<int,int>, int>> q;

int dfs(){
    int days =0;
    while(!q.empty()){
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        
        q.pop();
        //cout << 'z' << z <<'x' << x << 'y' << y << endl;
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h){
                continue;
            }
            if(visited[nz][nx][ny] >= 0) continue;
            visited[nz][nx][ny] = visited[z][x][y]+1;
            if(days < visited[nz][nx][ny]) days = visited[nz][nx][ny];
            q.push({{nz,nx},ny});
        }

    }
    return days;
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> h;

    for(int height=0; height<h; height++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> graph[height][i][j]; 
                if(graph[height][i][j]==1){
                    q.push({{height,i},j});
                }if(graph[height][i][j]==0){
                    visited[height][i][j] = -1;
                }
            }
        }
    }
    
    int result = dfs();
    for(int height=0; height<h; height++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (visited[height][i][j] == -1){
                    cout<< "-1";
                    return 0;
                } 

            }
            
        }
       
    }

     
    cout << result;


    return 0;
}