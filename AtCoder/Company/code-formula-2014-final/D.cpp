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
    vector<int> h(n);
    for(int i=0; i<n; i++) cin>>h[i];
    vector<ll> hsum(n+1);
    for(int i=0; i<n; i++) hsum[i+1] = hsum[i] + h[i];

    vector<vector<P>> movies(n);
    vector<int> ends;
    ends.emplace_back(0);
    for(int i=0; i<n; i++){
        int m, s, e; cin>>m>>s>>e;
        m--;
        movies[m].emplace_back(e, s);
        ends.emplace_back(e);
    }
    
    for(int i=0; i<n; i++){
        sort(all(movies[i]));
    }

    sort(all(ends));

    vector<ll> dp(100010, -1);
    dp[0] = 0;

    for(int i=0; i<ends.size(); i++){
        
        // どの種類を見るのか
        for(int j=0; j<n; j++){
            int end = ends[i];
            vector<int> cends;
            for(int k=0; k<movies[j].size(); k++){
                if(end <= movies[j][k].second){
                    end = movies[j][k].first;
                    cends.emplace_back(end);
                }
            }

            for(int k=0; k<cends.size(); k++){
                chmax(dp[cends[k]], dp[ends[i]] + hsum[k+1]);
            }
        }
    }
    
    cout << *max_element(all(dp)) << endl;

    return 0;
}