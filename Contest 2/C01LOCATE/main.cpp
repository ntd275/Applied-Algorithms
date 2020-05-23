#include <bits/stdc++.h>

using namespace std;

int n,m;
vector< pair <int , int > > img1,img2;
int a[2002][2002];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t;
            cin >> t;
            if(t) img1.push_back({i,j});
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t;
            cin >> t;
            if(t) img2.push_back({i,j});
        }
    }
    for(int i = 0; i < img1.size(); i++){
        for(int j = 0; j < img2.size(); j++){
            a[img1[i].first-img2[j].first+n][img1[i].second-img2[j].second+m]++;
        }
    }
    int res = 0;
    for(int i = 1; i < (n<<1); i++)
        for(int j = 1; j < (m<<1); j++)
           // if( i!=n || j != m)
                res = max(res,a[i][j]);
    cout << res << '\n';
    img1.clear();
    img2.clear();
    memset(a,0,sizeof a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
