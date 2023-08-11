#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
int n, m, u, v, out=0;
ii a, b;
int matrix[100][100];

bool val(int i, int j){
    if (i<=0 ||i>n) return false;
    if (j<=0 ||j>m) return false;
    if (matrix[i][j]) return false;
    return true;
}

void dfs(int i, int j, int dis){
    if (!val(i,j)) return;
    matrix[i][j]=1;
    if (i==b.first && j==b.second) out= max(out, dis);
    else{
        dfs(i,j+2, dis+2);
        dfs(i,j-2, dis+2);
        dfs(i+2,j, dis+2);
        dfs(i-2,j,dis+2);
    }
    matrix[i][j]=0;

}


int main(){
    _
    cin>> n >> m;
    cin >> u >> v; b = {u,v};
    cin >> u >> v; a = {u,v};

    dfs(a.first, a.second, 1);

    cout << out << endl;
}