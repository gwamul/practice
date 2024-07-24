#include <iostream>
#include <queue>

using namespace std;

/*

주사위
1~6
게임은 10 10 보드판에서 시작

보드판에는 숫자 써져있음

i번 칸에서 4 나오면 i+4로  이동
100 넘으면 이동 불가

도착한 칸이 사다리라면 사다리를 타고 위로 올라간다.
뱀이 있는 칸에 도착하면 뱀을 따라 내려간다.

목표 1에서 출발해서 100에 도착하기

주사위 돌려야 하는 최솟값을 구하시오


*/

int n,m;
int from, to;

int visited[101]={0,};
int board[101]={0,};
void bfs(int sp){
    queue<int> q;
    q.push(sp);
    visited[sp] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int next = cur + i;
            if(next>100) continue;

            if(board[next]!=0) next= board[next];

            if(!visited[next]){
                visited[next] = visited[cur] + 1;
                q.push(next);

                if(next == 100) return;
            }
            
        }
        

    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    // n : 사다리 m : 뱀

    while(n--){
        // 사다리 정보
        cin >> from >> to;
        board[from] = to; 
    }

    while(m--){
        // 뱀 정보
        cin >> from >> to;
        board[from] = to;
    }
    bfs(1);

    // for(int i=1; i<101; i++){
    //     //cout<< visited[i];
    //     cout << board[i];
    // }

    cout << visited[100];
    
    return 0;
}