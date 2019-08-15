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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    ll n, q; cin>>n>>q;
    map<ll, ll> cnt;
    for(int i=0; i<n; i++){
        ll a; cin>>a;
        cnt[a]++;
    }

    for(int i=0; i<q; i++){
        ll l, r, x; cin>>l>>r>>x;
        auto head = cnt.lower_bound(l);
        auto tail = cnt.upper_bound(r);

        ll ans=0;
        ll sum=0;
        vector<ll> v;
        while(head != tail){
            sum += head->second;
            if(head->second % 2 != 0){
                ans ^= head->first;
            }

            v.eb(head->first);
            head++;
        }

        cout << ans << endl;

        for(int j=0; j<v.size(); j++){
            cnt.erase(v[j]);
        }

        cnt[x] += sum;
    }
}
