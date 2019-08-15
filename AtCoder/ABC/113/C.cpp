#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<P>> g(n+10);
    for(int i=0; i<m; i++){
        int p, y; cin>>p>>y;
        p--;
        g[p].emplace_back(P(y, i));
    }

    for(int i=0; i<n; i++){
        sort(g[i].begin(), g[i].end());
    }

    int cnt=0;
    vector<string> ans(m);
    for(int i=0; i<n; i++){
        for(int j=0; j<g[i].size(); j++){
            int y, id;
            tie(y, id)=g[i][j];
            int hdigit=0, tdigit=0, head=i+1, tail=j+1;
            while(head>0){
                head/=10;
                hdigit++;
            }
            while(tail>0){
                tail/=10;
                tdigit++;
            }
            for(int k=1; k<=6-hdigit; k++) ans[id]+="0";
            ans[id]+=patch::to_string(i+1);
            for(int k=1; k<=6-tdigit; k++) ans[id]+="0";
            ans[id]+=patch::to_string(j+1);
        }
    }

    for(int i=0; i<m; i++){
        cout << ans[i] << endl;
    }
}
