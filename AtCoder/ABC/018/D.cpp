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
    int n, m, p, q, r; cin>>n>>m>>p>>q>>r;
    vector<int> x(r), y(r), z(r);
    for(int i=0; i<r; i++){
        cin>>x[i]>>y[i]>>z[i];
        x[i]--, y[i]--;
    }

    int ans=0;
    for(int wbit=0; wbit<(1<<n); wbit++){
        if(__builtin_popcount(wbit)!=p) continue;

        vector<int> sum(m, 0);
        for(int i=0; i<r; i++){
            if(wbit & (1<<x[i])){
                sum[y[i]]+=z[i];
            }
        }

        sort(sum.begin(), sum.end(), greater<int>());

        int psum=0;
        for(int i=0; i<q; i++){
            psum+=sum[i];
        }

        chmax(ans, psum);
    }
    cout << ans << endl;
}