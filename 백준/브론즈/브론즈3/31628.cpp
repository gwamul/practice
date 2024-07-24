#include <iostream>
#include <string>

using namespace std;

string s;
int able = 0;
int main(){
    string arr[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<10; i++){
        string temp = arr[i][0];
        for(int j=0; j<10; j++){
            if(temp != arr[i][j]){
                break;
            }  
            able = 1; 
        }
    }
    cout << able;
}