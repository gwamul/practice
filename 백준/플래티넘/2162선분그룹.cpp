#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;



struct coord{
    int x1, y1;
    int x2, y2;

};


int n;
int x1,y1,x2,y2;
int parent[3001];
int cnt[3001];
coord line[3001];

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    long long temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
    if(temp < 0) return -1;
    else if(temp > 0) return 1;
    return 0;
}

bool isCross(coord C1, coord C2){
    int x1 = C1.x1; int y1= C1.y1; int x2 = C1.x2; int y2 = C1.y2;
    int x3 = C2.x1; int y3= C2.y1; int x4 = C2.x2; int y4 = C2.y2;

    if( CCW(x1, y1, x2, y2, x3, y3) * CCW(x1,y1,x2,y2,x4,y4) <= 0 && 
        CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) <=0){
            if((x1>x3 && x1 > x4 && x2 > x3 && x2 > x4) || (x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return false;
            else if((y1>y3 && y1 > y4 && y2 > y3 && y2 > y4) || (y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return false;
            return true;
        }
    return false;

}


int find(int node){
    if(parent[node] == node) return node;
    else return find(parent[node]);
}

void unionSet(int a, int b){
    a = find(a); b=find(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}




int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
   
    //init
    for(int i=0; i<n; i++){
        cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
        parent[i] = i;
    }

    memset(cnt, 0, sizeof(cnt));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isCross(line[i], line[j])) unionSet(i,j);
        }
    }

    for(int i=0; i<n; i++){
        cnt[find(i)]++;
    }
    int gCount= 0;
    int Max = 0;

    for(int i=0; i<n; i++){
        if(cnt[i]) gCount++;
        Max = max(Max, cnt[i]);
    }
    
    cout << gCount <<'\n';
    cout << Max;



    return 0;
}