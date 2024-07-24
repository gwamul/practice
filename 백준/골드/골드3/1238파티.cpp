#include <iostream>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;
#define INF 1e9+7
int n, m, x;
int from, to, time;
vector<int> d[2];
vector<pair<int, int>> graph[2][1001];


void dijkstra(int start){
    d[start][x] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push({0,x});

    while(!pq.empty()){
        int current = pq. top(). second;
        int distance = pq.top().first;

        pq.pop();

        if(d[start][current] < distance) continue;
      
        for(int i=0; i<graph[start][current].size(); i++){
            int next = graph[start][current][i].second;
            int nextDistance = distance + graph[start][current][i].first;

            if(nextDistance < d[start][next]){
                d[start][next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
    }

}


int main(){
    cin >> n>> m >>x;
    
    
    for(int i=0; i<m; i++){
        cin >> from >> to >> time;
        graph[0][from].push_back({time, to});
        graph[1][to].push_back({time, from});
    }
    d[0].resize(n+1, INF);
    d[1].resize(n+1, INF);
    

    dijkstra(1);

    dijkstra(0);

    int res = 0;
    for(int i=1; i<=n; i++){
        res = max(res, d[0][i] + d[1][i]);
    }
    cout << res;
    return 0;


}