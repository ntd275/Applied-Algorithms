#include <bits/stdc++.h>

using namespace std;

int n,l,a[1005];

bool check(double x){
    double last = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i]-x > last) return 0;
        last = a[i] + x;
    }
    return last >= l;
}

double solve(){
    double l = 0, r = 1e10;
    while(r-l > 1e-10){
        double mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> l;
    for(int i = 1; i <=n ; ++i)
        cin >> a[i];
    sort(a+1,a+n+1);
    printf("%0.9f", solve());
    return 0;
}
