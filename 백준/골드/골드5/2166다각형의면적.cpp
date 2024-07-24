#include <iostream>
#include <vector>


using namespace std;



vector<pair<double, double>> v;


int n;
double x,y;


double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);//
    cout.tie(0);
    cin  >> n;
    
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }


    // for(int i=0;i<n; i++){
    //     cout << v[i].first << v[i].second;
    // }
    double result=0;
    for(int i=1; i<n; i++){
        result+= ccw(v[0].first,v[i-1].first,v[i].first, v[0].second, v[i-1].second, v[i].second);
    }
    if (result <0) result*=-1;
    cout<<fixed;
    cout.precision(1);
    cout << result;

}