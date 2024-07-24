#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
/*
dslr 계산기

0~10000 미만 십진수 레지스터

n 네자리수

d1 d2 d3 d4

d : d는 n을 2배로, 9999보다 크면 mod 10000
s : n-1 , n이 0이면 9999
l : 자릿수 왼 회전 1234 -> 2341
r : 자릿수 오 회전 1234 -> 4123

서로다른 두 정수 A,B에 대해 A 를 B로 바꾸는  최소한의 명령어
1234 3412


*/

queue<pair<int,string>> q;
int visited[10000] = {0,};
int N;



int a,b;


// int d(int x){
    
//     return 2*x%10000;
// }
// int s(int x){
//     if(x<1) return 9999;
//     else return x-1;
// }
// int l(int x){
//     int d1 = x/1000;
//     return (x%1000)*10+d1;
// }
// int r(int x){
//     int d4 = x%10;
//     return (x/10)+d4*1000;
// }


// void bfs(){
//     visited[a] = 1;
//     q.push({a,""});
//     while(!q.empty()){
//         int num = q.front().first;
//         string op = q.front().second;
        
//         //cout<<"d"<<d(num)<<" s"<<s(num)<<"  l"<<l(num)<<" r"<<r(num)<<'\n';
//         if(num==b){
//             cout << op << '\n';
//             return;
//         }
//         q.pop();
//         int dnum = d(num);
//         int snum = s(num);
//         int lnum = l(num);
//         int rnum = r(num);
//         if(!visited[dnum]){
//             visited[dnum] = 1;
//             q.push({dnum,op+"D"});
//         }
//         if(!visited[snum]){
//             visited[snum] = 1;
//             q.push({snum,op+"S"});
//         }
        
//         if(!visited[lnum]){
//             visited[lnum] = 1;
//             q.push({lnum,op+"L"});
//         }
//         if(!visited[rnum]){
//             visited[rnum] = 1;
//             q.push({rnum,op+"R"});
//         }
       
      
        
//     }

//}
void bfs()
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }

        int D, S, L, R, temp;
        // D 연산
        D = (cur_num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = true;
            q.push(make_pair(D, cur_op + "D"));
        }

        // S 연산
        S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!visited[S])
        {
            visited[S] = true;
            q.push(make_pair(S, cur_op + "S"));
        }

        // L 연산
        L = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(make_pair(L, cur_op + "L"));
        }

        // R 연산
        R = cur_num / 10 + (cur_num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = true;
            q.push(make_pair(R, cur_op + "R"));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> a >> b;
        
        memset(visited, 0, sizeof(visited));
        
        bfs();
        
        
    }
    
   

}