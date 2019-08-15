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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    double a, b, c; cin>>a>>b>>c;
    double lb=0, ub=200, t, f;
    while(abs(f-100)>0.000001){
        t=(lb+ub)/2;

        f=a*t+b*sin(c*t*pi);
    
        if(f<100) lb=t;
        else ub=t;
    }
    cout << fixed << setprecision(15) << t << endl;
}