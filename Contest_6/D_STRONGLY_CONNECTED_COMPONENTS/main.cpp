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

int n,m,cnt,res,num[100005],low[100005];
vector<int> g[100005];
stack<int> s;

void tarjan(int u){
    num[u] = low[u] = ++cnt;
    s.push(u);
    for(int v:g[u]){
        if(num[v]){
            low[u] = min(low[u],num[v]);
        }else{
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
    }
    if(num[u] == low[u]){
        ++res;
        while(s.top() != u){
            int v = s.top();
            num[v] = 1e9;
            s.pop();
        }
        num[u] = 1e9;
        s.pop();
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
    }

    for(int i = 1; i <= n; ++i){
        if(!num[i]) tarjan(i);
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
