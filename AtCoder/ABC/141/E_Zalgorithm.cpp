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

vector<int> Zalgorithm(string s){
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
    int i = 1, j = 0;
    while(i < n){
        while(i + j < n && s[j] == s[i+j]) ++j;
        a[i] = j;
        if(j == 0){++i; continue;}
        int k = 1;
        while(i + k < n && k + a[k] < j) a[i+k] = a[k], ++k;
        i += k; j -= k;
    }

    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;

    int ans = 0;
    for(int i=0; i<n; i++){
        string t = s.substr(i);
        auto v = Zalgorithm(t);
        for(int j=0; j<v.size(); j++){
            if(j >= v[j]) chmax(ans, v[j]);
        }
    }

    cout << ans << endl;

    return 0;
}