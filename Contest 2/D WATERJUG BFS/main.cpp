#include <bits/stdc++.h>

using namespace std;

bool dd[901][901];
struct state{
    int a,b;
    int d;
    state(int _a,int _b, int _d){
        a = _a;
        b = _b;
        d = _d;
    }
};

int limita,limitb,goal;

int main(){
    cin >> limita >> limitb >> goal;
    queue<state> q;
    state start = state(0,0,0);
    dd[0][0] = 1;
    q.push(start);
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if(cur.a == goal || cur.b == goal) {
            cout << cur.d;
            return 0;
        }
        state next = state(limita,cur.b,cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
        next = state(cur.a,limitb,cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
        next = state(0,cur.b,cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
        next = state(cur.a,0,cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
        next = state(max(0,cur.a+cur.b-limitb),min(limitb,cur.a+cur.b),cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
        next = state(min(limita,cur.a+cur.b),max(0,cur.a+cur.b-limita),cur.d+1);
        if(!dd[next.a][next.b]){
            dd[next.a][next.b] = 1;
            q.push(next);
        }
    }
    cout << -1;
    return 0;
}
