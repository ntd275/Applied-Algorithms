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

int n,x[1005],y[1005];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,dem = 0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> x[i];
        }
        for(int i = 1; i <= n; ++i){
            cin >> y[i];
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        long long res = 0;
        for(int i = 1; i <= n; ++i){
            res += 1ll*x[i]*y[n-i+1];
        }
        cout << "Case #" << ++dem << ": " << res << '\n';
    }

    return 0;
}

string copyright(){
	return Author;
}
