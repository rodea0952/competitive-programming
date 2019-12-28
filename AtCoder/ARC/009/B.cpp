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

    vector<int> b(10);
    for(int i=0; i<10; i++) cin>>b[i];
    vector<int> b2rank(10);
    for(int i=0; i<10; i++) b2rank[b[i]] = i;
    int n; cin>>n;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<bool> used(n, false);
    vector<string> ans(n);
    for(int i=0; i<n; i++){
        // i 回行なう
        for(int j=0; j<n; j++){
            if(used[j]) continue;
            // 残っている中で a[j] が最小と仮定
            bool valid = true;
            for(int k=0; k<n; k++){
                if(used[k]) continue;
                if(j == k) continue;

                if(a[j].size() > a[k].size()) valid = false;
                if(a[j].size() == a[k].size()){
                    for(int l=0; l<a[j].size(); l++){
                        int jrank = b2rank[a[j][l] - '0'];
                        int krank = b2rank[a[k][l] - '0'];

                        if(jrank < krank) break;
                        if(jrank > krank){
                            valid = false;
                        }
                    }
                }
            }

            if(valid){
                ans[i] = a[j];
                used[j] = true;
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}