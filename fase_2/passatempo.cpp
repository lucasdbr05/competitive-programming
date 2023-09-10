#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
map<string, int> dict;
int n, m;
string matrix[1000][1000];
int line_sum[1000], col_sum[1000];
set<string> s;

int main(){
    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){  
            cin >> matrix[i][j];
            s.insert(matrix[i][j]);
        }
        cin>>line_sum[i];
    }
    for (int j=0; j<m; j++) cin >> col_sum[j];

    while(dict.size()<s.size()){
        for (int i=0; i<n;i++){
            int qtt=0, val = 0;
            string aux;
            bool all=true;
            for (int j=0; j<m; j++){
                if (dict.find(matrix[i][j])==dict.end()){
                    if (!qtt){
                        qtt++;
                        aux = matrix[i][j];
                    }else{
                        if (matrix[i][j]!=aux) {all=false; break;}
                        else qtt++;
                    }
                }else {
                    val+= dict[matrix[i][j]];
                }
        }
        if (all and qtt){
            dict[aux]= (line_sum[i]-val)/qtt;
        }
    }
     for (int j=0; j<m;j++){
            int qtt=0, val = 0;
            string aux;
            bool all=true;
            for (int i=0; i<n; i++){
                if (dict.find(matrix[i][j])==dict.end()){
                    if (!qtt){
                        qtt++;
                        aux = matrix[i][j];
                    }else{
                        if (matrix[i][j]!=aux) {all=false; break;}
                        else qtt++;
                    }
                }else {
                    val+= dict[matrix[i][j]];
                }
        }
        if (all and qtt){
            dict[aux]= (col_sum[j]-val)/qtt;
        }
    }
    }

    for (auto elem: dict){
        cout << elem.first << " " << elem.second<< endl;
    }
}