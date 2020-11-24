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

    int n1; cin>>n1;
    vector<ll> a(n1);
    for(int i=0; i<n1; i++) cin>>a[i];
    int n2; cin>>n2;
    vector<ll> b(n2);
    for(int i=0; i<n2; i++) cin>>b[i];

    ll A = a[0];
    for(int i=1; i<n2; i+=2) A *= b[i];
    ll B = 1;
    for(int i=1; i<n1; i++) B *= a[i];
    for(int i=0; i<n2; i+=2) B *= b[i];

    if(0 < A * B){
        A = abs(A), B = abs(B);
        ll g = __gcd(A, B);
        cout << A / g << " " << B / g << endl;
    }
    else{
        A = abs(A), B = abs(B);
        ll g = __gcd(A, B);
        cout << - A / g << " " << B / g << endl;
    }

    return 0;
}