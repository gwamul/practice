#include <iostream>
#include <cstring>
using namespace std;



bool find(int x){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    string str = "";
    int M, x;
    int arr[21] = {0,};


    cin >> M;
    for(int i=0; i<M; i++){
        cin >> str;
        if (str == "add"){
            cin >> x;
            arr[x] = x;
        }
        else if(str == "remove"){
            cin >> x;
            arr[x] = 0;
        }
        else if(str == "check"){
            cin >> x;
            if(arr[x]==0) cout<<0<<'\n';
            else cout<<1<<'\n';

        }
        else if(str == "toggle"){
            cin >> x;
            if(arr[x]==x) arr[x]=0;
            else arr[x]=x;
        }
        else if(str == "all"){
            for(int i=0; i<21; i++){
                arr[i] = i;
            }
        }
        else if(str == "empty"){
            for(int i=0; i<21; i++){
                arr[i] = 0;
            }
        }
        else{
            return 0;
        }

        


    }





}