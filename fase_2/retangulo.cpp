#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, m,p, i, j, circ=0, d_p =0, dis=0;
int pontos[100005];
bool val= false;

void retangulo(){
    if (circ%2) return;
    p=0;
    dis=0;
    int h_circ = circ/2;
    for (int i=0; i<n; i++){
        while (dis<h_circ and p<n-1){
            dis+= pontos[p];
            p++;
        }

        if (dis==h_circ){
            d_p++;
            if (d_p>=2) { 
                val=true;
                break;
            }
        }
        dis -= pontos[i];
    }
    return;
}

int main(){
    cin >> n; circ=0;
    for (int i=0; i<n; i++){
        cin >> pontos[i];
        circ+= pontos[i];
    }
    // cout << circ << endl;
    retangulo();
    if (val){
        cout << "S"<< endl;
    }else{
        cout << "N" << endl;
    }


}