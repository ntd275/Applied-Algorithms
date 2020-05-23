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

string s;
stack<pair<char, int> > st1;
stack<pair<int, int> > st2;

void emptyst1(){
    while(!st1.empty()) st1.pop();
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    st2.push(mp(-2,-3));

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(' || s[i] == '[') {
            st1.push(mp(s[i],i));
            continue;
        }
        if(s[i] == ')' || s[i] == ']'){
            if(st1.empty()) {
                continue;
            }
            if(s[i] == ')' && st1.top().F != '('){
                emptyst1();
                continue;
            }
            if(s[i] == ']' && st1.top().F != '['){
                emptyst1();
                continue;
            }
            pair<int,int> t = mp(st1.top().S,i);
            st1.pop();
            while(st2.top().F > t.F && st2.top().S < t.S){
                st2.pop();
            }
            st2.push(t);
         }
    }

    pair< int,int> res = st2.top(),t = st2.top();
    st2.pop();
    int demres = 0;
    for(int i = t.F; i <= t.S; ++i){
        if(s[i] == '[') ++demres;
    }

    while(!st2.empty()){
        pair<int,int> temp = st2.top();
        st2.pop();

        if(temp.S+1 == t.F){
            t = mp(temp.F,t.S);
            continue;
        }
        int dem = 0;
        for(int i = t.F; i <= t.S;++i)
            if(s[i] == '[') ++dem;
        if(dem > demres){
            res = t;
            demres = dem;
        }

        t = temp;
    }

    cout << demres << '\n';
    for(int i = res.F; i <= res.S; ++i){
        cout << s[i];
    }

    return 0;
}

string copyright(){
	return Author;
}
