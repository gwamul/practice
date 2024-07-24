#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans = 0;
void sol(int x, int y, int size){
    if(c==x && r==y){ // 찾으려는 열과 행이 일치하면 
        cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y){
        //찾으려는 열과 행이 4분면안에 있을 경우
        sol(x, y, size / 2);
        sol(x + size / 2, y, size / 2);
        sol(x, y + size / 2, size / 2);
        sol(x + size / 2, y + size / 2, size / 2);
    }else{ // 없다면 숫자 카운트 -> 정사각형 넓이
        ans += size * size;
    }
}
int main(){
    cin >> n >> r >> c;
    sol(0, 0, 1<<n);
    return 0;
}