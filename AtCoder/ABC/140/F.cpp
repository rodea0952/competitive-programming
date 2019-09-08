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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> s(1<<n);
    multiset<int> st;
    for(int i=0; i<(1<<n); i++){
        cin>>s[i];
        st.insert(s[i]);
    }

    sort(s.begin(), s.end(), greater<int>());

    st.erase(s[0]);

    vector<int> v;
    v.emplace_back(s[0]);

    for(int i=0; i<n; i++){
        int sz = v.size();
        for(int j=0; j<sz; j++){
            auto itr = st.lower_bound(v[j]);
            if(itr == st.begin()) continue;

            itr--;
            v.emplace_back(*itr);
            st.erase(itr);
        }

        sort(v.begin(), v.end(), greater<int>());
    }

    if(v.size() == (1 << n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}