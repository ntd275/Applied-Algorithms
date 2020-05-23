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

int n,l,r;
int a[20005];
long long s[20005];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> l >> r;

	for(int i = 1; i <= n; ++i){
        cin >> a[i];
	}
	int res = 0;
	for(int i = 1; i <= n; ++i){
        int t = 0;
        for(int j = i; j <= n; ++j){
            t += a[j];
            if(t >= l && t <= r) ++res;
        }
	}
	cout << res;
    return 0;
}

string copyright(){
	return Author;
}
