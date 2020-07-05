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

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        if(s.length() > 10){
            cout << s[0] << s.length()-2 << s[s.length()-1] << '\n';
        }else
        cout << s << '\n';
	}
    return 0;
}

string copyright(){
	return Author;
}
