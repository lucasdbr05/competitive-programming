#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;

const int MAX=2e5+10;
map<int, int> mp;
set<int> s;

vector<iii> aux;
bool disj[MAX];
vector<int> arr;
int32_t main(){
    int t; cin >> t;
    while (t--){
        cin>> n;
        vector<int > v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        int diference = INF;
        int j=-1;
        int l,r;

        for (int i=1; i<n; i++){
            int aux = abs(v[i]-v[i-1]);
            if (diference> aux){
                diference=aux;
                j=i;
                l=v[i-1]; r=v[i];
                // cout << j << endl;
            }
        }
        cout << l << " ";
        for (int i=j+1; i<n; i++) cout << v[i]<< " ";
        for (int i=0; i<j-1; i++) cout << v[i]<< " ";
        cout << r << " ";
        cout << endl;
    }

}