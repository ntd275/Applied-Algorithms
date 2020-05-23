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

int n;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	vector<long long>t(n+1,0),f(n+1,0);
	t[1] = f[1] = 1;
    for(int i = 2; i <= n;++i){
        t[i] = (3*t[i-1] + f[i-1]) % M;
        f[i] = (2*t[i-1] + f[i-1]) % M;
    }
    cout << t[n];
    return 0;
}

string copyright(){
	return Author;
}
