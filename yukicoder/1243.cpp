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

    int t; cin>>t;
    while(t--){
        ll a, b; cin>>a>>b;
        vector<ll> ans1, ans2;
        while(a < b){
            ll g = __gcd(a, b);
            if((a / g) % 2){
                ans1.emplace_back(g);
                a += g;
            }
            else{
                ans2.emplace_back(g);
                b -= g;
            }
        }

        vector<ll> ans;
        reverse(all(ans2));
        for(auto i:ans1) ans.emplace_back(i);
        for(auto i:ans2) ans.emplace_back(i);

        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
    }

    return 0;
}