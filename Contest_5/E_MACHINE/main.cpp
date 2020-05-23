/*
	Author: DucNT
	Date:
*/
#include <bits/stdc++.h>
#define Author "DucNT"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define M 1000000007
#define PI 3.14159265358979323846264338328

using namespace std;

// gioi han de sai s,t < 1e7;
int f[10000005],g[10000005],n,res = -1,max_t;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; ++i){
        int s,t;
        cin >> s >> t;
        max_t = max(max_t,t);
        f[t] = max(f[t],t-s);
        g[s] = max(g[s],t-s);
	}

    for(int i = 1; i <= max_t; ++i){
        f[i] = max(f[i],f[i-1]);
    }

    for(int i = max_t; i >= 1; --i){
        g[i] = max(g[i+1],g[i]);
    }

    for(int i = 1; i <= max_t; ++i){
        if(f[i] && g[i+1]) res = max(res,f[i]+g[i+1]);
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
