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

	vector<int> f(n+5,2e9);

	for(int i = 1,x; i <= n; ++i){
        cin >> x;
        *lower_bound(f.begin(),f.end(),x) = x;
	}
    cout << lower_bound(f.begin(),f.end(),2e9)- f.begin();
    return 0;
}

string copyright(){
	return Author;
}
