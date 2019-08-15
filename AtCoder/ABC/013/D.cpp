#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m, d; cin>>n>>m>>d;
    vector<int> a(m), v1(n+1);
    for(int i=0; i<m; i++) cin>>a[i];
    for(int i=1; i<=n; i++) v1[i]=i;

    for(int i=0; i<m; i++){
        swap(v1[a[i]], v1[a[i]+1]);
    }

    vector<int> v2(n+1);
    for(int i=1; i<=n; i++){ // 1回のあみだ終了後
        v2[v1[i]]=i;
    }

    vector<vector<P>> g(n+10);
    vector<bool> canuse(n+10, true);
    int num=0;
    for(int i=1; i<=n; i++){
        int nv=i, cnt=0;
        bool plus=false;
        while(canuse[nv]){
            plus=true;
            //cout << nv << " " << num << endl;
            canuse[nv]=false;
            g[num].eb(P(nv, cnt));
            cnt++;
            nv=v2[nv];
        }
        if(plus) num++;
    }

    /*
    for(int i=0; g[i].size()!=0; i++){
        for(auto j : g[i]){
            cout << j.fs << " ";
        }
        cout << endl;
    }*/

    vector<int> ans(n+10);
    for(int i=0; g[i].size()!=0; i++){
        for(int j=0; j<g[i].size(); j++){
            ans[g[i][j].fs]=g[i][((d%g[i].size())+g[i][j].sc)%g[i].size()].fs;
        }
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}