#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const int MAX= 1e6+10;
const int INF= 0x3f3f3f3f;
int n, l, h, aux, out=-INF;
int s[MAX], memo[500000][100];
bitset<MAX> m;


int main(){
    cin >> n >> l >> h;
    m.reset();
    for (int i=0; i<n; i++){cin>>s[i];}
    for (int i=0; i<n; i++){cin>>aux;if (aux) m[i]=true;}
    memset(memo, -INF, sizeof(memo));
    if (m[0]){
        memo[0][0]=0;
        memo[0][1]=s[0];
    } else{
        memo[0][0]= max(0, s[0]);
    }

    for (int i=1;i<n;i++){
        for(int j=0;j<=h; j++){
            if (m[i]){
                if (!j) memo[i][j]=0;
                else{
                    if (memo[i-1][j-1]>-INF){
                        memo[i][j]= memo[i-1][j-1]+s[i];
                    }
                }
            } else{
                if (!j) memo[i][j]= max(0, memo[i-1][j]+s[i]);
                else{
                    if (memo[i-1][j]>-INF){
                        memo[i][j]= memo[i-1][j]+s[i];
                    }
                }
            }
        }

    }
    for (int i=0; i<n; i++){
        for(int j=l; j<=h; j++){
            out = max(out, memo[i][j]);
        }
    }
    cout << out << endl;
}