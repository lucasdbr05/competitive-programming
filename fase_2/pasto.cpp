
#include <bits/stdc++.h>
using namespace std;

int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

int n, m;
int vis[1010][1010];
char pasto[1010][1010];
bool fora_pasto;
int v=0,k=0,V=0,K=0;

bool isValid (int y, int x) {
  if (y < 0) return false;
  if (x < 0) return false;
  if (y >= n) return false;
  if (x >= m) return false;
  if (pasto[y][x]=='x') {fora_pasto=true; return false ;}
  if (pasto[y][x] == '#') return false;

  return true;
}


void DFS (int y, int x) {
  if (vis[y][x]) return;
    
  vis[y][x] = 1;
  if (pasto[y][x]=='v') v+= 1;
  if (pasto[y][x]=='k') k+= 1;
  for (int i = 0 ; i < 4 ; i++) {
    int newX = x + neighborX[i];
    int newY = y + neighborY[i];
    if (isValid(newY, newX)) {
        DFS(newY, newX);
    }
  }
}

int main() {
    cin >> n >> m;


    for (int i = 1 ; i <= n ; i++) {
      for (int j = 1 ; j <= m ; j++) {
        cin >> pasto[i][j];
      }
    }


    for (int i=0; i<=n+1; i++){pasto[i][0]='x'; pasto[i][m+1]='x';}
    for (int i=0; i<=m+1; i++){pasto[0][i]='x'; pasto[n+1][i]='x';}

   
    
    
    for (int i = 1 ; i <= n ; i++) {
      for (int j = 1 ; j <= m ; j++) {
        v=0; k=0;fora_pasto=false;
        if (pasto[i][j] != '#' && !vis[i][j]) {
            DFS(i, j);
        }
        if (!fora_pasto){
          if(v>=k){
              V+= v;
          } else{
              K+=k;
          }
        }
      }
    }

    cout << K << " "<< V << endl;
}


