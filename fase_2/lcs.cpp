#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 10000;
const int INF= 0x3f3f3f3f;

string s, t,ans;
int lens,lent;
int sz[3005][3005];

void recover(int i,int j){
    if (i>=lens or j>=lent) return;
    if (s[i]==t[j]) {ans.push_back(s[i]); recover(i+1, j+1); }
    else if (sz[i+1][j]>sz[i][j+1]){return recover(i+1,j); }
    else {return recover(i, j+1); }

}

int32_t main(){
    sws

    cin >> s >> t;

    lens = s.size(); lent = t.size();

    for (int i=lens-1; i>=0; i--){
        for (int j=lent-1;j>=0; j--){
            if (s[i]==t[j]) sz[i][j]=sz[i+1][j+1]+1;
            else sz[i][j] = max(sz[i+1][j], sz[i][j+1]);
        }
    }

    recover(0,0);

    cout << ans << endl;


}           