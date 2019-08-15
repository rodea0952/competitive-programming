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
    ll n, k; cin>>n>>k;
    vector<int> t(n), d(n);
    vector<vector<int>> kinds(n);
    for(int i=0; i<n; i++){
        cin>>t[i]>>d[i];
        t[i]--;
        kinds[t[i]].eb(d[i]);
    }

    vector<P> v;
    for(int i=0; i<n; i++){
        sort(kinds[i].begin(), kinds[i].end(), greater<int>());
        for(int j=0; j<kinds[i].size(); j++){
            v.eb(P(kinds[i][j], j==0?1:0));
        }
    }

    sort(v.begin(), v.end(), greater<P>());
    ll tsum=0, dsum=0;
    vector<int> normal;
    for(int i=0; i<k; i++){
        tsum+=v[i].sc;
        dsum+=v[i].fs;

        if(v[i].sc==0){
            normal.eb(v[i].fs);
        }
    }

    sort(normal.begin(), normal.end());

    ll ans=tsum*tsum+dsum;
    int cnt=0;
    for(int i=k; i<n; i++){
        if(v[i].sc==1){
            tsum+=v[i].sc;
            dsum+=v[i].fs;
            if(cnt<normal.size()) dsum-=normal[cnt++];
            else break;
        }
        chmax(ans, tsum*tsum+dsum);
    }
    cout << ans << endl;
}