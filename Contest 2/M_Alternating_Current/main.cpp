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

    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.length(); ++i){
        if(!st.empty()){
            if(st.top() == s[i]){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }

    if(st.empty()){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}

string copyright(){
	return Author;
}
