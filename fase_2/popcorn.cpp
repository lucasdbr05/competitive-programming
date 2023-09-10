#include <bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5+10;
#define endl '\n'


#define sws ios::sync_with_stdio(false);cin.tie(0);
int arr[MAX];
int n, c, t,l,r, ans;

bool check(int x){
    int comp = 1;
    int aux = 0;
    for(int i=1; i<=n; i++){
        if (aux+arr[i] <=x*t) {aux+= arr[i];}
        else{
            aux =0;
            comp++;
            i--;
        }
        if (comp>c) return true;
    }
    
    return false;
}

int32_t main(){
    sws 
    cin >> n >> c>> t;
    for(int i=1; i<=n; i++){
        cin>> arr[i];
    }
    l=1, r= 1e9+10;

    while (l<r){
        int m = (l+r)/2;
        if (check(m)){l=m+1; } 
        else{ r=m;}
    }
    cout << l<<endl;


}