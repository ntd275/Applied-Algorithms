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

int n,m,k,root[25],res=1e9,dem,b[25];

struct edge
{
    int u,v,w;
} a[35];

int getroot(int u)
{
    return root[u] ? root[u] = getroot(root[u]) : u;
}

bool cmp(edge a,edge b){
    return a.w < b.w;
}

void update(){
    memset(root,0,sizeof root);
    vector<edge> temp;
    for(int i = 1; i <= m; ++i){
        if(b[a[i].u] && b[a[i].v]){
            temp.pb(a[i]);
        }
    }
    sort(temp.begin(),temp.end(),cmp);
    int cnt = 0,s = 0;
    for(auto t:temp){
        int p = getroot(t.u);
        int q = getroot(t.v);
        if(p != q){
            ++cnt;
            s += t.w;
            root[p] = q;
        }
    }
    if(cnt == k) res = min(res,s);
}

void Try(int x)
{
    if(x > n)
    {
        return;
    }
    b[x] = 1;
    ++dem;
    if(dem == k+1)
    {
        update();
    }
    else
    {
        Try(x+1);
    }
    --dem;
    b[x] = 0;
    Try(x+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    Try(1);
    cout << res;

    return 0;
}

string copyright()
{
    return Author;
}
