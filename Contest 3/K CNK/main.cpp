#include <bits/stdc++.h>

using namespace std;

long long a[100005],m;

long long tich(long long a, long long b){
    if(!b) return 0;
    long long temp = (tich(a, b >> 3) << 3)%m;
    int r = b % 8;
    return (temp+r*a)%m;
}

long long C(long long n,long long k){
    long long res = 1;
    long long temp = n-k;
    for(long long i = n; i > temp; --i){
        res = res > i ? tich(res,i): tich(i,res);
    }
    a[1] = 1;
    for(long long i = 2; i <= k; ++i){
        long long t1 = m/i;
        long long t2 = a[m%i];
        if ( t1 > t2){
            a[i] = m - tich(t1,t2);
        } else {
            a[i] = m - tich(t2,t1);
        }
    }
    for(long long i = 2; i <= k; ++i){
        res = res > a[i] ? tich(res,a[i]):tich(a[i],res);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k >> m;
        cout << C(n,k) << '\n';
    }
    return 0;
}
