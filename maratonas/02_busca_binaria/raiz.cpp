#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for (int i=x; i<n;i++)
typedef long long int lli;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);



int main(){_ 
    cout << fixed<< setprecision(15);

    double N; cin >> N;
    double l = 0, r= 1e8+10, eps = 1e-9;

    loop(0,1000){
        double m = (l+r)/2;
        if (m*m>N) r=m;
        else l= m;
    }
    cout << (l+r)/2<< endl;
    return 0;

}