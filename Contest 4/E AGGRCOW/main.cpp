#include <bits/stdc++.h>

using namespace std;

int n,c,a[100005];

bool check(int x){
    int last = a[1];
    int dem = 1;
    for(int i = 2; i <= n; ++i){
        if(a[i] - last >= x){
            ++dem;
            last = a[i];
        }
    }
    return dem >= c;
}

int solve(){
    int l = 0,r = 2e9;
    while(r - l > 1){
        int mid = (l+r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a+1,a+n+1);
        cout << solve() << '\n';
    }
    return 0;
}
