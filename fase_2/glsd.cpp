#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1010;
const int INF= 0x3f3f3f3f;
int n, m;
int dp[MAX][MAX];

int main(){
    cin >> n >> m;
    if (m==0){
        if (n==1) cout << "0 0"<< endl;
        else cout << "-1 -1"<< endl;
        return 0;
    }
    memset(dp, -1 , sizeof dp);
    
    vector<int> maior, menor;
    int sum_maior=0, sum_menor=0;
    int i=n;
    int aux = m;
    while (i){
        int num =min(9, max(aux, 0));
        aux -= num;
        maior.push_back(num);
        sum_maior+= num;
        i--;
    }
    bool stw0=maior.back()==0;
    for (int j=n-1; j>=0; j--){
        if (stw0){
            if (j==n-1) menor.push_back(1);
            else {
                if (maior[j]==0) {
                    menor.push_back(0);
                }else{
                    menor.push_back(maior[j]-1);
                    stw0=false;
                }
            }
        } else{
            menor.push_back(maior[j]);
        }
        sum_menor+= maior[j];
    }
    if (sum_maior==m and sum_menor==m){
        for (auto x: menor) cout << x;
        cout << " ";
        for (auto x: maior) cout << x;
        cout << endl;
        return 0;
    } else{
         cout << "-1 -1"<< endl;
        return 0;
    }
    
}