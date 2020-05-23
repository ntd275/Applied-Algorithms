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

int f[1000005],n,res = -1e9;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1,x;i <= n; ++i){
        cin >> x;
        f[i] = f[i-1] < 0 ? x : f[i-1]+x;
        res = max(res,f[i]);
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
