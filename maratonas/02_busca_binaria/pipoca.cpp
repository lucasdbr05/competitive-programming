#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;
#define endl '\n'

#define _ ios::sync_with_stdio(false);cin.tie(0);
int pip[MAX];
int n, c,t ;

bool possivel(lli kick){
    int comp=1;
    lli resta = t*kick;
    for(int i=0; i<n; i++){
        if (resta >= pip[i]) resta -= pip[i];
        else {
            comp++;
            resta = t*kick;
            i--;
        }
    if (comp>c) return false;
    }
    return true;
}

int main(){_ 
    cin >> n >> c>> t;
    for(int i=0; i<n; i++){
        cin>> pip[i];
    }
    int l=0, r= 1e9+1;

    while (l<r){
    int m = (l+r)/2;
    if (!possivel(m)) l= m+1;
    else r=m;
    }
    cout << l<<endl;


}