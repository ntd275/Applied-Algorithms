/*
	Author: DucNT
	Date: 10/4/2020
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

int n,k;
int a[5005];
int dem[100005];
long long res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j)
            ++dem[a[j]];
        for(int j = i+1; j <=n; ++j){
            --dem[a[j]];
            int t = k - a[i] - a[j];
            if(t > 0){
                res += dem[t];
            }
        }
    }
    cout << res;

    return 0;
}

string copyright(){
	return Author;
}
