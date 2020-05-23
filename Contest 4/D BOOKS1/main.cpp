#include <bits/stdc++.h>

using namespace std;

int m,k,p[505],slash[505];
long long res = 0;

bool check(long long x){
    int dem = 1;
    long long s = x;
    for(int i = 1; i <= m; ++i){
        if(p[i] > x) return 0;
        if(p[i] <= s) s -= p[i];
        else {
            ++dem;
            s = x - p[i];
        }
    }
    return dem <= k;
}

void solve(){
    long long l = 0, r = 1e10;
    while(r-l > 1){
        long long mid = (l+r) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    res = r;
}

void opt(){
    long long t = res;
    int dem = k;
    for(int i = m; i >= 1; --i){
        if(t >= p[i] && i >= dem ) t -= p[i];
        else {
            slash[i] = 1;
            t = res - p[i];
            --dem;
        }
    }
}

void out(){
    for(int i = 1; i <= m; ++i){
        cout << p[i] << ' ';
        if(slash[i]) cout << "/ ";
    }
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        cin >> m >> k;
        for(int i = 1; i <= m; ++i)
            cin >> p[i];
        memset(slash,0,sizeof slash);
        solve();
        opt();
        out();
    }
    return 0;
}
