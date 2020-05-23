#include <bits/stdc++.h>

using namespace std;

int n,b;
long long a[200005], st[800005];

void build(int id,int l,int r)
{
    if( r == l)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1,l,mid);
    build((id<<1)+1,mid+1,r);
    st[id] = max(st[id << 1],st[(id << 1)+1]);
}

long long get(int id,int l,int r, int a, int b){
    if(r < a) return -1;
    if(l > b) return -1;
    if(l >= a && r <= b) return st[id];
    int mid = (l+r) >> 1;
    return max(get(id << 1,l,mid,a,b),get((id << 1)+1,mid+1,r,a,b));
}

int main()
{
    cin >> n >> b;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,1,n);
    long long res = -1;
    for(int i = 2; i < n; i++){
        long long l = get(1,1,n,1,i-1);
        long long r = get(1,1,n,i+1,n);
        if(l-a[i] >= b && r-a[i] >= b){
            res = max(res,l+r-(a[i] << 1));
        }
    }
    cout << res;
    return 0;
}
