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
    ll a, b, q; cin>>a>>b>>q;
    vector<ll> s(a), t(b);
    for(int i=0; i<a; i++) cin>>s[i];
    for(int i=0; i<b; i++) cin>>t[i];

    while(q--){
        ll x; cin>>x;
        
        // A -> B
        ll cur;
        ll aid, bid;
        ll asum, bsum;
        ll sum1=INF, sum2=INF;
        aid=(lower_bound(s.begin(), s.end(), x) - s.begin());
        if(aid==0){
            asum=s[aid]-x;
            cur=s[aid];

            bid=(lower_bound(t.begin(), t.end(), cur) - t.begin());
            if(bid==0) bsum=t[bid]-cur;
            else if(bid==b) bsum=cur-t[bid-1];
            else bsum=min(t[bid]-cur, cur-t[bid-1]);
            sum1=asum+bsum;
        }
        else if(aid==a){
            asum=x-s[aid-1];
            cur=s[aid-1];

            bid=(lower_bound(t.begin(), t.end(), cur) - t.begin());
            if(bid==0) bsum=t[bid]-cur;
            else if(bid==b) bsum=cur-t[bid-1];
            else bsum=min(t[bid]-cur, cur-t[bid-1]);
            sum1=asum+bsum;
        }
        else{
            // go right
            asum=s[aid]-x;
            cur=s[aid];

            bid=(lower_bound(t.begin(), t.end(), cur) - t.begin());
            if(bid==0) bsum=t[bid]-cur;
            else if(bid==b) bsum=cur-t[bid-1];
            else bsum=min(t[bid]-cur, cur-t[bid-1]);
            chmin(sum1, asum+bsum);
            
            // go left
            asum=x-s[aid-1];
            cur=s[aid-1];
            bid=(lower_bound(t.begin(), t.end(), cur) - t.begin());
            if(bid==0) bsum=t[bid]-cur;
            else if(bid==b) bsum=cur-t[bid-1];
            else bsum=min(t[bid]-cur, cur-t[bid-1]);
            chmin(sum1, asum+bsum);
        }
        //cout << "sum1= " << sum1 << endl;

        // B -> A
        bid=(lower_bound(t.begin(), t.end(), x) - t.begin());
        if(bid==0){
            bsum=t[bid]-x;
            cur=t[bid];

            aid=(lower_bound(s.begin(), s.end(), cur) - s.begin());
            if(aid==0) asum=s[aid]-cur;
            else if(aid==a) asum=cur-s[aid-1];
            else asum=min(s[aid]-cur, cur-s[aid-1]);
            sum2=asum+bsum;
        }
        else if(bid==b){
            bsum=x-t[bid-1];
            cur=t[bid-1];

            aid=(lower_bound(s.begin(), s.end(), cur) - s.begin());
            if(aid==0) asum=s[aid]-cur;
            else if(aid==a) asum=cur-s[aid-1];
            else asum=min(s[aid]-cur, cur-s[aid-1]);
            sum2=asum+bsum;
        }
        else{
            // go right
            bsum=t[bid]-x;
            cur=t[bid];

            aid=(lower_bound(s.begin(), s.end(), cur) - s.begin());
            if(aid==0) asum=s[aid]-cur;
            else if(aid==a) asum=cur-s[aid-1];
            else asum=min(s[aid]-cur, cur-s[aid-1]);
            chmin(sum2, asum+bsum);
            
            // go left
            bsum=x-t[bid-1];
            cur=t[bid-1];

            aid=(lower_bound(s.begin(), s.end(), cur) - s.begin());
            if(aid==0) asum=s[aid]-cur;
            else if(aid==a) asum=cur-s[aid-1];
            else asum=min(s[aid]-cur, cur-s[aid-1]);
            chmin(sum2, asum+bsum);
        }

        //cout << "ans" ;
        cout << min(sum1, sum2) << endl;
    }
}