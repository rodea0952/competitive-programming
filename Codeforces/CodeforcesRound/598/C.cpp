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
 
    int n, m, d; cin>>n>>m>>d;
    vector<int> c(m);
    for(int i=0; i<m; i++) cin>>c[i];
 
    ll max_n = (d - 1) * (m + 1) + accumulate(c.begin(), c.end(), 0);
 
    if(n <= max_n){
        cout << "YES" << endl;
        vector<int> a;
        for(int i=0; i<m; i++){
            for(int j=0; j<d-1; j++){
                a.emplace_back(0);
            }
            for(int j=0; j<c[i]; j++){
                a.emplace_back(i + 1);
            }
        }
        for(int i=0; i<d-1; i++){
            a.emplace_back(0);
        }    
 
        int sz = a.size();
        vector<bool> willuse(sz, true);
        int nousecnt = 0;
        for(int i=0; i<sz; i++){
            if(sz - nousecnt == n) break;
 
            if(a[i] == 0){
                willuse[i] = false;
                nousecnt++;
            }
        }
 
        int outcnt = 0;
        for(int i=0; i<sz; i++){
            if(willuse[i]){
                outcnt++;
                if(outcnt == n) cout << a[i] << endl;
                else cout << a[i] << " ";
            }
        }
    }
    else{
        cout << "NO" << endl;
    }
 
    return 0;
}