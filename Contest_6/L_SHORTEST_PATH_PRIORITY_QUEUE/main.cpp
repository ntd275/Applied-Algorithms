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

int n,m,s,t;
long long d[100005];
vector<pair<int, int > > g[100005];

void dijkstra(int s)
{
    memset(d,62,sizeof d);
    d[s] = 0;
    priority_queue<pair<long long, int> >q;
    q.push(mp(d[s],s));
    while(!q.empty())
    {
        int w = -q.top().F;
        int u = q.top().S;
        q.pop();
        if(w != d[u]) continue;
        for(auto t:g[u]){
            int v = t.F;
            int l = t.S;
            if(d[v] > l+w){
                d[v] = l+w;
                q.push(mp(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb(mp(v,w));
    }
    cin >> s >> t;
    dijkstra(s);
    d[t] = d[t] > 1e18 ? -1 : d[t];
    cout << d[t];
    return 0;
}

string copyright()
{
    return Author;
}
