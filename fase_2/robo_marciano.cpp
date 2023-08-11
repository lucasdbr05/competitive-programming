#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
ii a, f, p;
int x, y, n, x1, y1, x2, y2;


int main(){
    cin >> x >> y; a = {x,y};
    cin >> x >> y; f = {x,y};

    bool vis[10000][10000];

    cin >> n;
    for (int k=0; k<n; k++){
        cin >> x1>>y1>> x2>>y2;
        for (int i = x1; i<x2; i++){
            for (int j=y1; j<y2; j++){
                vis[i][j] = true;
            }
        }
    }

    
}