#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> esum(n+1, 0);
    for(int i=0; i<n; i++){
        esum[i+1] = esum[i] + (s[i] == 'E');
    }

    vector<ll> asum(n+1, 0);
    for(int i=0; i<n; i++){
        asum[i+1] = asum[i] + a[i];
    }

    vector<pair<ll, int>> ae;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            ae.emplace_back(asum[i] - asum[j-1], esum[i] - esum[j-1]);
        }
    }

    sort(all(ae));
    for(int i=0; i+1<ae.size(); i++){
        chmax(ae[i+1].second, ae[i].second);
    }

    int q; cin>>q;
    vector<int> k(q);
    for(int i=0; i<q; i++) cin>>k[i];

    for(int i=0; i<q; i++){
        auto itr = upper_bound(all(ae), pair<ll, int>(k[i], inf));

        if(itr == ae.begin()){
            cout << 0 << endl;
        }
        else{
            itr--;
            pair<ll, int> ans = *itr;
            cout << ans.second << endl;
        }
    }

    return 0;
}