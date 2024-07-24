#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    vector<int> v;
    int n,m;
    int f,l,k;
    cin >> n>> m;
    v.resize(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    

    for(int i=0; i<m; i++){
        cin >> f >> l >> k;
        vector<int> temp(v.begin()+f-1, v.begin()+l);
        sort(temp.begin(), temp.end());
        for(int index = 0; index<temp.size(); index++){
            cout << temp[index];
        }
        cout << temp[k-1] <<endl;
    }
    
        
   

}
