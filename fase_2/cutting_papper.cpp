#include <bits\stdc++.h>
using namespace std;

#define endl '\n'
typedef pair<int, int> ii;


int solve(int n,const vector<int>& heigths){
    vector <int> x;

    x.push_back(0);
    for (auto h: heigths){
        if (x.back()!=h){
            x.push_back(h);
        }
    }
    x.push_back(0);

    n = (int) x.size();

    map<int, int> y;
    const int PICO= -1, VALE=1;

    for (int i = 1; i< n; ++ i){
        if (x[i-1]< x[i] and x[i]>x[i+1]) y[x[i]]+= PICO;
        if (x[i-1]> x[i] and x[i]<x[i+1]) y[x[i]]+= VALE;
    }

    int ans = 2, pieces =2;

    for (auto aux_y : y){
        auto delta = aux_y.second;

        pieces += delta;
        ans = max(ans, pieces);
    }
    return ans;
}


int main(){
    ios:: sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int N; cin>> N;

    vector<int> h(N);

    for (int i = 0; i<N; ++i) {cin>> h[i];}

    auto ans = solve(N,h);

    cout << ans << endl;
}