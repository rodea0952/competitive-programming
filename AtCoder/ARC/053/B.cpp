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

    string s; cin>>s;
    int n = s.size();
    vector<int> cnt(26, 0);
    
    for(int i=0; i<n; i++){
        cnt[s[i] - 'a']++;
    }

    int ocnt = 0, ecnt = 0;
    for(int i=0; i<26; i++){
        if(cnt[i] % 2){
            ocnt++;
            ecnt += (cnt[i] - 1) / 2;
        }
        else{
            ecnt += cnt[i] / 2;
        }
    }

    if(ocnt == 0){
        cout << n << endl;
        return 0;
    }
    
    int ans = ecnt / ocnt * 2 + 1;
    
    cout << ans << endl;

    return 0;
}