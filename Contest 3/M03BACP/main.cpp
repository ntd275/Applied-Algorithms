#include <bits/stdc++.h>

using namespace std;

int n,m,c[17],a[17][17],b[17],deg[17],tt[17],dem[6],be[17],en[17];
int res=1e9;

vector< int > g[17];

void update(){
    int t = 0;
    for(int i = 1; i <= m;++i){
        t = max(t,dem[i]);
    }
    res = min(res,t);
}

void Try(int x){
    if(x == n+1) {
        update();
        return;
    }
    int t = tt[x];
    for(int i = be[t]; i <= en[t] ; i++){
        b[t] = i;
        vector<int> temp;
        for(int j = 0; j < g[t].size(); ++j){
            int v = g[t][j];
            temp.push_back(be[v]);
            be[v] = max(be[v],i+1);
        }
        dem[i] += c[t];
        Try(x + 1);
        dem[i] -= c[t];
        for(int j = 0; j < g[t].size(); ++j){
            int v = g[t][j];
            be[v] = temp[j];
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            int t;
            cin >> t;
            if(t){
                g[j].push_back(i);
                ++deg[i];
            }
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(!deg[i]) q.push(i);
    }
    int d = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        tt[d++] = u;
        for(int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            --deg[v];
            if(!deg[v]) q.push(v);
        }
    }

    for(int i = 1; i <= n; ++i){
        be[i] = 1;
        en[i] = m;
    }

    Try(1);
    cout << res;
    return 0;
}
