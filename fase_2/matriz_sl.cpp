#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, m, i, j;
int matrix[1005][1005];
int hist[1005];


int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j< m; j++){
            cin >>matrix[i][j];
        }
    }

   int out = 0;
   for (int i=0; i<n-1; i++){
        for (int j=0; j< m-1; j++){
            if (matrix[i][j]+matrix[i+1][j+1]<=matrix[i][j+1]+matrix[i+1][j]){
                hist[j]++;
            }else{
                hist[j]=0;
            }
        }
        int ptr=0;
        int h[1005], s[1005];
        for (int k=0; k< m-1; k++){
            int l =k;

            while(ptr>0 and hist[k]< h[ptr-1]){
                out = max(out,(k-s[ptr-1]+1)*(h[ptr-1]+1));
                l=s[ptr-1];
                --ptr;
            }
            h[ptr]=hist[k];
            s[ptr++]=l;
        }
        while(ptr>0){
            out = max(out, (m-s[ptr-1])*(h[ptr-1]+1));
            ptr--;
        }
   }
    cout << out << endl;
}