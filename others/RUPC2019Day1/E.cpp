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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // dp[i] := 長さが i+1 であるような増加部分列における最終要素の最小値
    vector<int> dp(n, 1e9);
    vector<vector<int>> g(n);
    for(int i=0; i<n; i++){
        g[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()].push_back(a[i]);
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }

    ll ans=0;
    int gmax=1e9;
    for(int i=n-1; i>=0; i--){
        if(g[i].size()){
            sort(g[i].begin(), g[i].end(), greater<int>());
            for(auto j:g[i]){
                if(j<gmax){
                    gmax=j;
                    ans+=j;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}