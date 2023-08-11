#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
typedef long long int ll;
const int INF= 0x3f3f3f3f;
const int MAX= 1e6+10;

int n, k, out=INF, x;
vector<int> p;



int main(){
    _ios_
    cin>> n >> k;

    //p.resize(n+1);p.clear();

    for (int i=0; i<n; i++){
        cin>>x;p.push_back(x);
    }
    sort(p.begin(), p.end());

    for(int i=0; i<n-k; i++){
        out = min(out, p[i+k]-p[i]);
    }

    cout << out << endl;
}