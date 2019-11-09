#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<ll> a(n), b(n);
    vector<T> sum(n);
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        sum[i]=T(a[i]+b[i], a[i], b[i]);
    }

    sort(sum.begin(), sum.end(), greater<T>());

    ll asum=0, bsum=0;
    for(int i=0; i<n; i++){
        ll x, y, z;
        tie(x, y, z)=sum[i];
        if(i%2==0) asum+=y;
        else bsum+=z;
    }
    cout << asum-bsum << endl;
}
