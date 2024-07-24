#include <iostream>
#include <queue>

using namespace std;

int desi, desj;
int n, m;
int graph[1001][1001];
int visited[1001][1001] = {-1,};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>> q;
void bfs(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout <<'x'<< x <<'y'<< y << endl;
        q.pop();
        for(int i=0; i<4;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx<0 || newx>=n || newy <0 || newy >=m ) continue;
            if(graph[newx][newy]==0) continue;
            if(visited[newx][newy]!= -1) continue;
            visited[newx][newy] = visited[x][y] + 1;
            q.push({newx, newy});
            //cout << 'x' <<x<< 'y' <<y<< endl;
            
        }


    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = -1;
        }
    }
    for(int i =0; i<n; i++){
        for(int j=0; j<m ;j++){
            int temp;
            cin >> temp;
            graph[i][j] = temp;
            if(temp == 2){
                q.push({i,j});
                visited[i][j] = 0;
                
            }
        }
    }
    //cout << desi << desj <<endl;
    bfs();
  
    for(int i =0; i<n; i++){
        for(int j=0; j<m ;j++){
            if(graph[i][j]==0) cout << 0 <<' ';
            else cout << visited[i][j]<<' ';
            
        }
        cout << '\n';
    }
}