#include <bits/stdc++.h>

using namespace std;

int solve(){
    string s;
    stack<char> st;
    cin >> s;
    for(int i = 0; i < s.length();i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == '}' && st.top() == '{')
                st.pop();
             else if(s[i] == ']' && st.top() == '[')
                    st.pop();
                   else if(s[i] == ')' && st.top() == '(')
                        st.pop();
                        else return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
