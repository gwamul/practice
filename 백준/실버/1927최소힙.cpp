#include <iostream>
#include <queue>
using namespace std;
/*



*/

priority_queue<int, vector<int>, greater<int>> p_queue;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >>x;
        if(x==0){
            if(p_queue.empty()) cout<<0<<'\n';
            else{
                cout<< p_queue.top() <<'\n';
                p_queue.pop();
            }
        }else{
            p_queue.push(x);
        }
    }
    
}