#include <bits/stdc++.h>

using namespace std;

int n,m,d[11][31],dem[11],res = 40;
vector < int > dd[31];

void update(){
    int t = 0;
    for(int i = 1; i <= m; i++)
        t = max(t,dem[i]);
    res = min(res,t);
}

void Try(int x){
    if(x == n+1) {
            update();
            return;
    }
    for(int i = 1; i <= m; i++){
        if(d[i][x]){
            dem[i]++;
            if(dem[i] >= res)
            {
                dem[i]--;
                continue;
            }
            vector< int > t;
            for(int j = 0; j < dd[x].size(); j++){
                int u = dd[x][j];
                if(d[i][u]){
                    d[i][u] = 0;
                    t.push_back(u);
                }
            }
            Try(x+1);
            dem[i]--;
            for(int j = 0; j < t.size(); j++){
                d[i][t[j]] = 1;
            }
        }
    }

}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int k;
        cin >> k;
        for(int j  = 1; j <= k; j++){
            int t;
            cin >> t;
            d[i][t] = 1;
        }
    }
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        int u,v;
        cin >> u >> v;
        dd[u].push_back(v);
        dd[v].push_back(u);
    }
    Try(1);
    res = res == 40?-1:res;
    cout << res;
    return 0;
}
