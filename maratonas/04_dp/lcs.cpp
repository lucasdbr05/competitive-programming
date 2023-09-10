#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int INF =0x3f3f3f3f;
const int MAX= 1e6;
string s, t, ans;
int s_size, t_size;
int lcs_size[5000][5000];


int dp(int i, int j){
    if (i>=s_size||j>=t_size) return 0;
    if (s[i]==t[j]) {return 1+dp(i+1, j+1);}
    return max(dp(i+1,j), dp(i, j+1));
}


void recover(int i, int j){
    if (i>=s_size || j>=t_size) return ;
    if (s[i]==t[j]){ans.push_back(s[i]);recover(i+1, j+1);}
    else if(lcs_size[i+1][j]>lcs_size[i][j+1]) return recover(i+1, j);
    else return recover(i, j+1);
    
}

int main(){
    cin >> s >> t;
    s_size = s.size();
    t_size = t.size();


    for(int i=s_size-1; i>=0; i--){
        for(int j =t_size-1;j>=0; j--){
            if(s[i]==t[j]) lcs_size[i][j] = 1+lcs_size[i+1][j+1];
            else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
        }
    }

    // cout <<dp(0,0)<< endl;
    recover(0,0);

    cout << ans << endl;

}