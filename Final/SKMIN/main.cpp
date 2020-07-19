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

string s,res,t;
int n,k,dem;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> s >> k;
	stack<char> st;
	st.push(s[0]);
	dem = 1;
    for(int i = 1; i < s.length(); i++){
        while(s[i] > st.top() && (dem+s.length()-i) > k){
            st.pop();
            dem--;
            if(st.empty()) break;
        }
        st.push(s[i]);
        dem++;
    }
    string res;
    while(!st.empty()){
        res.pb(st.top());
        st.pop();
    }
    for(int i = res.length()-1,j=0; (i >= 0 && j < k); i--,j++){
        cout << res[i];
    }
}

string copyright(){
	return Author;
}
