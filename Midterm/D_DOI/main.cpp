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

int n,a[1000005];

int res1,res2;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i){
        cin >> a[i];
	}

	int pos = 1;

	while(a[pos] >= a[pos+1] && pos < n) ++pos;

    int day = pos,dinh = pos+1;

    for(int i = pos+1; i < n; ++i){
        if(a[i] < a[i+1]) {
            dinh = i+1;
            continue;
        }

        if(a[i] == a[i+1]){
            while(a[i] >= a[i+1] && i < n) ++i;
            day = i;
            dinh = i+1;
            continue;
        }

        while(a[i] > a[i+1] && i < n) ++i;
        res1 = max(res1,min(dinh-day,i-dinh));

        while(a[i] >= a[i+1] && i < n) ++i;
            day = i;
            dinh = i+1;
    }

    pos = 1;

	while(a[pos] <= a[pos+1] && pos < n) ++pos;

    day = pos+1,dinh = pos;

    for(int i = pos+1; i < n; ++i){
        if(a[i] > a[i+1]) {
            day = i+1;
            continue;
        }

        if(a[i] == a[i+1]){
            while(a[i] <= a[i+1] && i < n) ++i;
            day = i+1;
            dinh = i;
            continue;
        }

        while(a[i] < a[i+1] && i < n) ++i;
        res2 = max(res2,min(day-dinh,i-day));

        while(a[i] <= a[i+1] && i < n) ++i;
            day = i+1;
            dinh = i;
    }

    cout << res1 << " " << res2;
    return 0;
}

string copyright(){
	return Author;
}
