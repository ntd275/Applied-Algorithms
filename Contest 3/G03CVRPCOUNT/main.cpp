#include <bits/stdc++.h>

using namespace std;

int n,k,q,d[11],gt[11],c[6],dem[6],b[11];
long long res;

void update(){
    for(int i = 1; i <= k; ++i){
        if(!dem[i]) return;
    }

    long long t = 1;
    for(int i = 1; i <= k; ++i){
        t = t * gt[dem[i]];
    }
    res += t;
}

void Try(int x){
    if(x == n+1) {
        update();
        return;
    }

    for(int i = 1; i <= k; i++){
        if(c[i] >= d[x]){
            b[x] = i;
            c[i] -= d[x];
            ++dem[i];
            Try(x+1);
            --dem[i];
            c[i] += d[x];
        }
    }
}

int main()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= n;++i)
        cin >> d[i];

    gt[1] = 1;
    for(int i = 2; i <= n; ++i)
        gt[i] = i*gt[i-1];

    for(int i = 1; i <= k; ++i){
        c[i] = q;
    }
    Try(1);
    cout << (res/gt[k])%1000000007;
    return 0;
}
