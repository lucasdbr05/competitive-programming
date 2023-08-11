#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef pair<int, int> ii;
const int INF = 1e5+10;
const int MAX = 2*1e5+10;

int n,m,q,a,b,w,x, ans=INF;
ii p;
vector<vector<ii>> path(MAX);
int dist_ua[MAX];
int dist_as[MAX];

vector<int> f;
bitset<MAX> vis;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    memset(dist_ua, INF, sizeof (dist_ua));
    vis.reset();
    dist_ua[s] = 0;
    pq.push({0,s});

    while (!pq.empty()){
        p = pq.top(); pq.pop();
        if (vis[p.second]) continue;
        vis[p.second]=true;
        
        for(auto num: path[p.second]){
            if (dist_ua[num.second]>num.first+dist_ua[p.second]){
                dist_ua[num.second]=num.first+dist_ua[p.second];
                pq.push({dist_ua[num.second], num.second});
            }
        }
    }


    
        memset(dist_as, INF, sizeof (dist_as));
        vis.reset();
        dist_as[n]=0; 
        pq.push({0,n});


        while (!pq.empty()){
        p = pq.top(); pq.pop();
        if (vis[p.second]) continue;
        vis[p.second]=true;
        
        for(auto num: path[p.second]){
            if (dist_as[num.second]>num.first+dist_as[p.second]){
                dist_as[num.second]=num.first+dist_as[p.second];
                pq.push({dist_as[num.second], num.second});
            }
        }
    
    }
}



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m >> x;

    for (int i =0;i<m;i++){
        cin>> a >> b >> w;
        path[a].push_back({w,b});
        path[b].push_back({w,a});
    }


    while(x--){
        cin >> q;
        f.push_back(q);
    }

    dijkstra(1);
    for (int amg: f){
        ans = min(ans, (dist_ua[amg]+ dist_as[amg]));

    }

    cout << ans << endl;
}