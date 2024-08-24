#include <iostream>
#include <queue>

using namespace std;

int n, e;
int a,b,c;
int v1, v2;
int distance = 0;
int array[801][801] = {0,};
int visited[801] = {0,};

queue<int> q;

void bfs(){
    int start = q.front();
    visited[start] = 1;
    

    while(!q.empty()){
        q.pop();
        
    }


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;
    while(e--){
        cin >> a >> b >> c;
        array[a][b] = c;
        array[b][a] = c;
    }

    cin >> v1 >> v2;
    
    q.push(v1);
    visited[v1] = 1;

    bfs();



    return 0;
}