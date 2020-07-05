/*
	Author: DucNT
	Date:
*/
#include <bits/stdc++.h>
#define Author "DucNT"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define M 1000000007
#define PI 3.14159265358979323846264338328

using namespace std;

int n,k,c[5005],d[5005],dd[5005];
vector <int> g1[5005];
int g2[5005][5005];


void BFS(int u){
    memset(dd,0,sizeof dd);
    queue< pair<int ,int> > q;
    q.push(mp(u,d[u]));
    while(!q.empty()){
        pair <int , int> x = q.front();
        --x.S;
        q.pop();
        for(auto v: g1[x.F]){
            g2[u][v] = min(g2[u][v],c[u]);
            if(!dd[v] && x.S){
                dd[v] = 1;
                q.push(mp(v,x.S));
            }
        }
    }
}

void IJK(){
    memset(d,62,sizeof d);
    priority_queue<pair <int , int > >q;
    d[1] = 0;
    q.push(mp(-d[1],1));
    while(!q.empty()){
        int u = q.top().S;
        int w = -q.top().F;
        q.pop();
        if(w != d[u]) continue;
        if(u == n) return;
        for(int i = 1; i <= n; ++i){
            int v = i;
            int l = g2[u][v];
            if(w+l < d[v]){
                d[v] = w+l;
                q.push(mp(-d[v],v));
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> c[i] >> d[i];
    }
    for(int i = 1; i <= k; ++i){
        int u,v;
        cin >> u >> v;
        g1[u].pb(v);
        g1[v].pb(u);
    }

    memset(g2,62,sizeof g2);
    for(int i = 1; i <= n; ++i){
        BFS(i);
    }

    for(int i = 1; i <= n; ++i){
        g1[i].clear();
    }

    IJK();

    cout << d[n];

    return 0;
}

string copyright(){
	return Author;
}
