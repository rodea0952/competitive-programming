#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, W; cin>>n>>W;
    vector<int> v(n), w(n);
    bool v_small=true, w_small=true;
    for(int i=0; i<n; i++){
        cin>>v[i]>>w[i];
        if(v[i]>1000) v_small=false;
        if(w[i]>1000) w_small=false;
    }

    if(w_small){
        vector<vector<ll>> dp(n+10, vector<ll>(W+10, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<=W; j++){
                if(j-w[i]>=0) dp[i+1][j]=max(dp[i][j], dp[i][j-w[i]]+v[i]);
                else dp[i+1][j]=dp[i][j];
            }
        }
        cout << dp[n][W] << endl;
    }
    else if(v_small){
        vector<vector<ll>> dp(n+10, vector<ll>(200010, INF));
        dp[0][0]=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=200000; j++){
                if(j-v[i]>=0) dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
                else dp[i+1][j]=dp[i][j];
            }
        }

        ll ans=0;
        for(int i=0; i<=200000; i++){
            if(dp[n][i]<=W) ans=i;
        }
        cout << ans << endl;
    }
    else{ // n <= 30
        vector<P> x1, x2;
        for(int i=0; i<n; i++){
            if(i<n/2) x1.eb(P(w[i], v[i]));
            else x2.eb(P(w[i], v[i]));
        }

        vector<P> x3;
        for(int bit=0; bit<(1<<(int)x2.size()); bit++){ // 後ろを半分全列挙  
            ll sumw=0, sumv=0;
            for(int i=0; i<x2.size(); i++){
                if(bit & (1<<i)){
                    sumw+=x2[i].fs;
                    sumv+=x2[i].sc;
                }
            }

            if(sumw>=W) continue;

            x3.eb(P(sumw, sumv));
        }

        sort(x3.begin(), x3.end());
        for(int i=0; i<x3.size()-1; i++){
            int cw, cv, nw, nv;
            tie(cw, cv)=x3[i];
            tie(nw, nv)=x3[i+1];
            if(cv>nv) x3[i+1]=P(nw, cv);
        }

        ll ans=0;
        for(int bit=0; bit<(1<<(int)x1.size()); bit++){ // 前を半分全列挙
            ll sumw=0, sumv=0;
            for(int i=0; i<x1.size(); i++){
                if(bit & (1<<i)){
                    sumw+=x1[i].fs;
                    sumv+=x1[i].sc;
                }
            }

            if(sumw<=W){
                ll tv=(lower_bound(x3.begin(), x3.end(), P(W-sumw, INF))-1)->sc; // iterator
                chmax(ans, sumv+tv);
            }
        }
        cout << ans << endl;
    }
}