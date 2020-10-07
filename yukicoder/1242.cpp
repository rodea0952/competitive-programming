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

    ll n; cin>>n;
    int k; cin>>k;
    vector<ll> a(k);
    for(int i=0; i<k; i++) cin>>a[i];

    set<ll> st;
    for(int i=0; i<k; i++) st.emplace(a[i]);

    for(int i=0; i<k; i++){
        if(10 < a[i]){
            if(st.count(a[i] + 5) || st.count(a[i] + 3) || st.count(a[i] + 1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for(int i=10; i>=2; i--){
        if(st.count(i) != 0){
            if(st.count(i + 5)) st.emplace(i - 1);
            if(st.count(i + 3)) st.emplace(i - 2);
            if(st.count(i + 1)) st.emplace(i - 3);
        }
    }

    cout << (st.count(1) ? "No" : "Yes") << endl;

    return 0;
}