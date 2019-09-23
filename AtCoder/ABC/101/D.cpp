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

double snuke(ll i){
    int digit = 0;
    ll num = i;
    while(0 < num){
        digit += num % 10;
        num /= 10;
    }
    return 1. * i / digit;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k; cin>>k;

    vector<ll> v;
    for(int i=1; i<=9; i++) v.emplace_back(i);

    ll base = 9;
    for(int i=0; i<14; i++){
        for(int j=1; j<=999; j++){
            string s = to_string(j) + to_string(base);
            v.emplace_back(stoll(s));
        }

        base *= 10;
        base += 9;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(snuke(v[i]) > snuke(v[j])){
                v.erase(v.begin() + i--);
                break;
            }
        }
    }

    for(int i=0; i<k; i++) cout << v[i] << endl;

    return 0;
}
