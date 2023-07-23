#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int INF= 0x3f3f3f;

typedef pair<int, int> ii;

bool cmp(ii x, ii y){
    return x.second < y.second;
}

int main(){_
    int qtt;
    cin >> qtt;
    
    vector<ii> m;
    for (int i = 0; i< qtt; i++){
        int x=0,y=0;
        cin >> x >> y;
        m.push_back({x,y});
    }
    
    sort(m.begin(), m.end(), cmp);
    
    int fim=-1;
    int ans =0;
    for (auto i: m){
        if(i.first >=fim){
            ans++;
            fim = i.second;
        }
    }
    
    cout << ans << endl;
    return 0;
}
