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

template <typename T> inline string toString(const T &a){ostringstream oss; oss<<a; return oss.str();};

int main(){
    int n; cin>>n;
    vector<int> t(n), v(n);
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> sumt(n+10, 0);
    for(int i=1; i<=n; i++){
        sumt[i]=sumt[i-1]+t[i-1];
    }

    vector<double> maxv(40010, 0);
    int cnt=0;
    for(int i=1; i<sumt[n]*2; i++){
        if(2*sumt[cnt]<i && i<2*sumt[cnt+1]){
            maxv[i]=v[cnt];
        }
        else if(i==2*sumt[cnt+1]){
            maxv[i]=min(v[cnt], v[cnt+1]);
            cnt++;
        }
    }

    /*
    for(int i=0; i<=sumt[n]*2; i++){
        cout << i << " " << maxv[i] << endl;
    }*/

    for(int i=1; i<=sumt[n]*2; i++){
        maxv[i]=min(maxv[i], maxv[i-1]+0.5);
    }

    for(int i=sumt[n]*2-1; i>=0; i--){
        maxv[i]=min(maxv[i], maxv[i+1]+0.5);
    }

    /*
    for(int i=0; i<=sumt[n]*2; i++){
        cout << i << " " << maxv[i] << endl;
    }*/

    double ans=0;
    for(int i=0; i<sumt[n]*2; i++){
        ans+=1.*(maxv[i]+maxv[i+1])/4;
    }
    cout << fixed << setprecision(10) << ans << endl;
}