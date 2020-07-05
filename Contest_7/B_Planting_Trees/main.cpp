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

int n,a[100005],res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i = 1; i <= n ; ++i){
        res = max(res,i+a[i]+1);
    }
    cout << res;

    return 0;
}

string copyright(){
	return Author;
}
