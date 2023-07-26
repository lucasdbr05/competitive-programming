#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);


int main(){_
    int n; cin>>n;
    vector<int> v;
    for (int i=0; i<n; i++){int x; cin>>x; v.push_back(x);}
    int soma_ant = -INF; int ans = -INF;

    for (int i = 0; i< n; i++){
        if (soma_ant <0) soma_ant = max(soma_ant, v[i]);
        else soma_ant += v[i];
        if (soma_ant> ans) ans = soma_ant;
    }
    cout<< ans<< endl;
}