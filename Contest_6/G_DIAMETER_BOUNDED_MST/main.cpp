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

int n,m,k,root[20],res=1e9,dem,b[30],s,d[20];

struct edge
{
    int u,v,w;
} a[30];

vector<int> g[20];

int getroot(int u)
{
    return root[u] ? getroot(root[u]) : u;
}

int DFS(int u){
    int max1=0,max2=0;
    for(auto v:g[u]){
        if(!d[v]){
            d[v] = 1;
            int t = 1+DFS(v);
            if(t > max1){
                max2 = max1;
                max1 = t;
            } else {
                if(t > max2){
                    max2 = t;
                }
            }
        }
    }
    s = max(s,max1+max2);
    return max1;
}

void update(){
    for(int i = 1; i <= n; ++i) g[i].clear();
    int t,sum = 0;
    for(int i = 1; i <= m; ++i)
        if(b[i]){
            g[a[i].u].pb(a[i].v);
            g[a[i].v].pb(a[i].u);
            sum += a[i].w;
            t = a[i].u;
        }
    s = 0;
    memset(d,0,sizeof d);
    d[t] = 1;
    s = max(s,DFS(t));
    if( s <= k) res = min(res,sum);
}

void Try(int x){
    if(x > m) return;
    int p = getroot(a[x].u);
    int q = getroot(a[x].v);
    if(p != q){
        root[p] = q;
        b[x] = 1;
        if(++dem == n-1){
            update();
        } else {
            Try(x+1);
        }
        --dem;
        b[x] = 0;
        root[p] = 0;
    }
    Try(x+1);
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    Try(1);
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
