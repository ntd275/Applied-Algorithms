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

int dd[1000005];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;
	queue<pair<int,int> > q;
	q.push(mp(s,0));
	while(!q.empty()){
        int c = q.front().F;
        int cnt = q.front().S;
        q.pop();
        if(c == g){
            cout << cnt;
            return 0;
        }
        int temp = c+u;
        if(temp <= f && !dd[temp]){
            dd[temp] = 1;
            q.push({temp,cnt+1});
        }
        temp = c-d;
        if(temp >= 1 && !dd[temp]){
            dd[temp] = 1;
            q.push({temp,cnt+1});
        }
	}
	cout << "use the stairs";
    return 0;
}

string copyright(){
	return Author;
}
