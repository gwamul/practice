#include <iostream>

#include <algorithm>

using namespace std;


long long int v[100001];


int n;
int x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    

    for(int i=0; i<n; i++){
        cin >> x;
        v[i] = x;
    }


  
    
    long long int min = 1000000;
    int left = 0;
    int right = n-1;
    long long int resA, resB;

    while(left < right){
        long long int mid = v[left] + v[right];
        if(min >= abs(mid)){
            min = abs(mid);
            resA = v[left];
            resB = v[right];
        }
        if(mid < 0){
            left++;
        }
        else if(mid >=0){
            right--;
        }
    }

    cout << resA <<" " << resB << '\n';


}