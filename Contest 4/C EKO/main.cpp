#include <bits/stdc++.h>

using namespace std;

int n,m,a[1000005];

bool check(int x){
    long long dem = 0;
    for(int i = 1; i <= n; ++i){
        dem += a[i]-x > 0 ? a[i]-x : 0;
    }
    return dem >= m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int l = 0,r = 1e9;
    while(r-l > 1){
        int mid = (l+r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
