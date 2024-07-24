#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> edges;
unordered_map<int, vector<int>> tree;
int N;

int sol(int idx){
    int winner=1;
    for(int i=0; i<N-1; ++i){
        
    }


    return winner;
}

int main() {
    int  result;
    cin >> N;
    edges.resize(N);
    
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    
    for (int i = 1; i <= N; ++i) {
        result = sol(i);
        cout << result << endl;
    }
    
    return 0;
}
