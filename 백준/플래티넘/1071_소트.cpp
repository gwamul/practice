/*N개의 정수가 주어지면, 이것을 연속된 두 수가 연속된 값이 아니게 정렬(A[i] + 1 ≠ A[i+1])하는 프로그램을 작성하시오. 
가능한 것이 여러 가지라면 사전순으로 가장 앞서는 것을 출력한다.

입력
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 
둘째 줄에는 N개의 수가 주어진다. N개의 수는 1,000보다 작거나 같은 자연수 또는 0이다.
*/


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n;
vector<int> v;

void swap(int a, int b){
    int temp = b;
    b = a;
    a = temp;
}

void main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());


}