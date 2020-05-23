#include <bits/stdc++.h>

using namespace std;

long long n,a[1000002];
long long l[1000002],r[1000002];

void solve(){
    stack<long long> s;
    s.push(0);
    a[0] = -1;
    for(int i = 1; i <= n; i++){
        while(a[s.top()] >= a[i]) s.pop();
        l[i] = s.top() + 1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n+1);
    a[n+1] = -1;
    for(int i = n; i >= 1; i--){
        while(a[s.top()] >= a[i]) s.pop();
        r[i] = s.top() - 1;
        s.push(i);
    }
    long long res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, 1ll*(r[i]-l[i]+1)*a[i]);
    }
    cout << res << endl;
}

int main(){
    while(1){
        cin >> n;
        if(n==0) return 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
