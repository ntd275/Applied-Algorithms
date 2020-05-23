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

int n,l,r;
long long a[1000005],f[1000005];
long long st[4000005];

void update(int id, int l, int r, int a, long long v){
    if(a > r || a < l) return;
    if(l == r){
        st[id] = v;
        return;
    }
    int mid = (l+r) >> 1;
    update(id << 1,l,mid,a,v);
    update((id << 1)+1,mid+1,r,a,v);
    st[id] = max(st[id << 1],st[(id << 1)+1]);
}

long long get(int id, int l, int r, int a, int b){
    if(r < a || l > b) return 0;
    if(l >= a && r <= b) return st[id];
    int mid = (l+r) >> 1;
    return max(get(id << 1,l,mid,a,b),get((id << 1)+1,mid+1,r,a,b));
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        long long t = get(1,1,n,i-r,i-l);
        f[i] = a[i] + t;
        update(1,1,n,i,f[i]);
    }
    long long res = 0;
    for(int i = n; i >= n-r; --i){
        res = max(res,f[i]);
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
