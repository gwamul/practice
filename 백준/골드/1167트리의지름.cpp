// #include <iostream>
// #include <vector>

// using namespace std;


// /*
// 트리의 지름:
// 트리에서 임의의 두 점 사이 거리 중 가장 긴 것
// 트리가 입력으로 주어짐

// 정점의 개수 v
// v개 간선 정보
// 정점 번호는 1~v로 
// */

// int v;
// int from, to, weight;
// vector<pair<int,int>> graph[100001];
// int visited[100001] = {0,};
// int selected;
// int dist = 0;
// void dfs(int sp, int cnt){
//     int to;
//     if(dist < cnt){
//         selected = sp;
//         dist = cnt;
//     }
//     for(int i=0; i<graph[sp].size(); i++){
//         int nsp = graph[sp][i].first;
//         int weight = graph[sp][i].second;

//         if(!visited[nsp]){
//             visited[nsp] = 1;
//             dfs(nsp, cnt+weight);
//             visited[nsp] = 0;
//         }
//     }
// }



// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> v;

//     for(int i = 0; i<v; i++){
//         cin >> from;
        
//         while(true){
//             cin >> to;
//             if(to == -1) break;
//             cin >> weight;
//             graph[from].push_back({to, weight});
//             graph[to].push_back({from, weight});
//         }
        

       
        
        
//     }
//     visited[1] = 1;
//     dfs(1,0);
//     fill(visited, visited+100001, 0);
//     dist = 0;
//     visited[selected] = 1;

//     dfs(selected,0);
//     cout << dist;    
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;
vector<pair<int,int>> v[100001];
bool visited[100001] = {false,};
int selected; // 찾은 리프 노드
int dist = 0; // 답(최대 거리)

// dfs(현재 노드, 현재 거리)
void dfs(int x, int cnt){

    // 현재 거리가 저장된 최대 길이보다 길다면,
    // 리프 노드와 최대 길이값 갱신
    if(dist < cnt){
        selected = x;
        dist = cnt;
    }

    // 일반적인 dfs
    for(int i = 0; i < v[x].size(); i++){
        int nx = v[x][i].first;
        int cost = v[x][i].second;
        if(!visited[nx]){
            visited[nx] = true;
            dfs(nx,cnt+cost);
            visited[nx] = false;
        }
    }
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> V;
    for(int i = 1; i <= V; i++){
        int s, e, c;
        cin >> s;
        while(true){
            cin >> e;
            if(e == -1) break;
            cin >> c;
            v[s].push_back({e,c});
        }
    }
    visited[1] = true;
    dfs(1,0); // 임의의 노드를 무조건 노드 1로 잡음
    fill(visited,visited+100001,false); // 방문 초기화
    dist = 0; // 거리 초기화
    visited[selected] = true; 
    dfs(selected,0); // 찾은 노드로 다시한번 dfs
    cout << dist;
}