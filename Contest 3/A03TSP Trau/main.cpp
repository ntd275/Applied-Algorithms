#include <bits/stdc++.h>

using namespace std;

vector< pair< int, int> > g[21];
int c[21][21];
int n, m;
int best = 1e9;
int s = 0;
bool d[21];

void Try(int x, int u){
    if (s >= best) return;
    if(x == n) {
        if(c[u][1] != 0 && s+c[u][1] < best)
            best = s+c[u][1];
        return;
    }
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i].first;
        int w = g[u][i].second;
        if(!d[v]){
            d[v] = 1;
            s += w;
            Try(x+1,v);
            d[v] = 0;
            s -= w;
        }
    }

}

bool cmp( pair<int,int> x, pair<int , int> y){
    return x.first < y.first;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
        c[u][v] = w;
    }
    d[1] = 1;
    for(int i = 1; i <= n; i++)
        sort(g[i].begin(),g[i].end(),cmp);
    Try(1,1);
    cout << best;
    return 0;
}
