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

    int n, k; cin>>n>>k;
    string s; cin>>s;

    map<vector<int>, int> r;
    vector<int> cnt(26, 0);
    
    for(int i=0; i<k-1; i++){
        cnt[s[i] - 'a']++;
    }

    bool valid = false;
    for(int i=k-1; i<n; i++){
        cnt[s[i] - 'a']++;

        if(r.find(cnt) == r.end()){
            r[cnt] = i;
        }
        else{
            if(r[cnt] < i - k + 1) valid = true;
        }

        cnt[s[i - (k - 1)] - 'a']--;
    }

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}