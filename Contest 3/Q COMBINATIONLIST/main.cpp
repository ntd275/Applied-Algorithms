#include <bits/stdc++.h>

using namespace std;

long long n,m,k;

map<int,map<int , long long > > f;

int a[10005];

long long C(int k, int n){
    if (f[k][n]) return f[k][n];
    int x = n-k;
    if( x < k) return C(x,n);
    if( k == n) return 1;
    if( k == 0) return 1;
    long long t = C(k,n-1) + C(k-1,n-1);
    t = min(t,(long long)1e10);
    f[k][n] = t;
    return t;
}

int main()
{
    cin >> n >> m >> k;

    if( k > C(m,n)){
        cout << -1;
        return 0;
    }
    int t = 1;
    for(int i = 1; i <= m; ++i){
        int x = m-i;
        int y = n-t;
        long long temp = C(x,y);
        while(k > temp){
            k -= temp;
            ++t;
            --y;
            temp = C(x,y);
        }
        a[i] = t;
        t++;
    }

    for(int i = 1; i <= m; ++i){
        cout << a[i] << ' ';
    }

    return 0;
}
