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
	string s = "/";
	while(n--){
        string x;
        cin >> x;
        if(x == "pwd") {
            cout << s << '\n';
            continue;
        }
        string y;
        cin >> y;
        string t = "";
        if(y[0] == '/'){
            s = "";
        }
        for(int i = 0; i < y.length(); ++i){
            if(y[i] == '/'){
                s += t + '/';
                t = "";
                continue;
            }
            if(y[i] == '.'){
                ++i;
                s.pop_back();
                while(s[s.length()-1] != '/') s.pop_back();
                s.pop_back();
                continue;
            }
            t+= y[i];
        }
        s+= t + '/';
	}


    return 0;
}

string copyright(){
	return Author;
}
