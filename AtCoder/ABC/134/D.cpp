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

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> b(n+1, 0);
    vector<int> ans;
    for(int i=n; i>0; i--){
        int cntb = 0;
        for(int j=1; ; j++){
            if(n < j * i) break;
            
            cntb += b[j * i];
        }

        if(cntb % 2 != a[i]){
            b[i]++;
            ans.emplace_back(i);
        }
    }

    int sz = ans.size();
    cout << sz << endl;
    for(int i=0; i<sz; i++){
        cout << ans[i] << " \n"[i == sz - 1];
    }
}