#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    ll n; cin>>n;
    vector<ll> t(n), a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>t[i]>>a[i]>>b[i];
        t[i]--;
    }

    ll ok = -1e9, ng = *min_element(a.begin(), a.end()) + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        vector<vector<ll>> LtoR(n+10);
        for(int i=0; i<n; i++){
            ll d = (a[i] - mid) / b[i];
            ll l = max(0LL, t[i] - d);
            ll r = min(t[i] + d, n - 1);
            LtoR[l].eb(r);
        }

        priority_queue<ll, vector<ll>, greater<ll>> R;

        bool valid = true;
        for(int i=0; i<n; i++){
            for(auto r : LtoR[i]) R.push(r);

            if(R.size() == 0){
                valid = false;
                break;
            }

            int r = R.top(); R.pop();

            if(r < i){
                valid = false;
                break;
            }
        }

        if(valid) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}
