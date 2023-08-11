#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int, int> ii;
const int INF=0x3f3f3f3f;
int n,m, aux;
int  T=INF, L=INF;
char path[1010][1010];
int visT[1010][1010];
int visL[1010][1010];
ii pT[1010][1010];
ii pL[1010][1010];
vector<ii> ansT;
vector<ii> ansL;
queue<ii> qT;
queue<ii> qL;
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

ii t,l;



int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    for (int i =1;i<=n;++i){
        for (int j =1;j<=m;++j){
            cin >> path[i][j];
            visT[i][j]=0;
            visL[i][j]=0;
            if (path[i][j]=='T'){
                t={i,j};
            } if (path[i][j]=='L'){
                l={i,j};
            }
        }
    }

    

    visT[t.first][t.second]=1;
    qT.push(t);
    
    while (!qT.empty()){
        ii p;
        p = qT.front(); qT.pop();
        
        for (int f=0; f<4;f++){
            int i=0,j=0;
            i= p.first+neighborY[f];
            j= p.second+neighborX[f];
            
            if ((0>=j || j>m)||(0>=i || i>n)) continue;
            if (path[i][j]=='#') continue;
            if (visT[i][j]) continue;
            visT[i][j]=1;
            
            pT[i][j]=p;
            
            qT.push({i,j});

            if ((i==1 || i==n)||(j==1||j==m)) ansT.push_back({i,j});
        }
    }
        if (!ansT.empty()){
            ii p_aux; char c_aux;
            for(auto pp : ansT){
            aux=0;

            p_aux = pp;
            while (p_aux!= t) {
                c_aux = path[p_aux.first][p_aux.second];
                if (c_aux=='F') aux += 0;
                else if (c_aux=='P') aux += 2;
                else aux += 1;
                p_aux = pT[p_aux.first][p_aux.second];
            }
            T= min(T, aux)+1;
            }
        } else{
            T= -1;
        }

    

    

    visL[l.first][l.second]=1;
    qL.push(l);
    
    while (!qL.empty()){
        ii p;
        p = qL.front(); qL.pop();

        for (int f=0; f<4;f++){
            int i,j;
            i= p.first+neighborY[f];
            j= p.second+neighborX[f];
            if ((0>=j || j>m)||(0>=i || i>n)) continue;
            if (path[i][j]=='#') continue;
            if (visL[i][j]) continue;

            visL[i][j]=1;

            pL[i][j]=p;
            qL.push({i,j});

            if ((i==1 || i==n)||(j==1||j==m)) ansL.push_back({i,j});
        }
    }
        if (!ansL.empty()){
            ii p_aux; char c_aux;
            for(auto pp : ansL){
            aux=0;

            p_aux = pp;
            while (p_aux!= l) {
                c_aux = path[p_aux.first][p_aux.second];
                if (c_aux=='C') aux += 0;
                else if (c_aux=='A') aux += 2;
                else aux += 1;
                p_aux = pL[p_aux.first][p_aux.second];
            }
            L= min(L, aux)+1;
            }
        } else{
            L= -1;
        }



    cout << T << " " << L << endl;
}