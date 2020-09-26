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
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    bool zero = false;
    for(int i=0; i<n; i++){
        if(a[i] == 0) zero = true;
    }

    if(zero){
        cout << -1 << endl;
    }
    else{
        ll num = 1;
        for(int i=0; i<n; i++){
            if(4 <= a[i]){
                cout << MOD << endl;
                return 0;
            }
            else{
                ll numu = 1;
                for(int j=1; j<=a[i]; j++){
                    numu *= j;
                }
                for(int j=1; j<=numu; j++){
                    num *= a[i];
                    if(MOD < num){
                        cout << MOD << endl;
                        return 0;
                    }
                }
            }
        }

        cout << MOD % num << endl;
    }

    return 0;
}