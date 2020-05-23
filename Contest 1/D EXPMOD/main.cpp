#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long a,b;

long long Exp(long long a, long long b){
    if(b <= 1) return a%MOD;
    long long t = Exp(a,b>>1);
    t = (t*t)% MOD;
    if(b & 1) return (t*a)%MOD;
    return t;
}


int main()
{
    cin >> a >> b;
    cout << Exp(a,b);
    return 0;
}
