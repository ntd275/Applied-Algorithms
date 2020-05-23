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

int n,m,root[100005];
long long res;

struct edge{
    int u,v,w;
}a[100005];

bool cmp(edge a,edge b){
    return a.w < b.w;
}

int getroot(int u){
    return root[u] ? root[u] = getroot(root[u]): u;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    for(int i = 1; i <= m; ++i){
        int p = getroot(a[i].u);
        int q = getroot(a[i].v);
        if(p != q){
            root[p] = q;
            res += a[i].w;
        }
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
