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
 
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        vector<int> p(n);
        for(int i=0; i<n; i++){cin>>p[i]; p[i]--;}
        vector<bool> used(n-1, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == p[j]){
                    for(int k=j-1; k>=0; k--){
                        if(p[k] > p[k+1] && !used[k]){
                            used[k] = true;
                            swap(p[k], p[k+1]);
                        }
                        else goto END;
                    }
                }
            }
            END:;
        }
 
        for(int i=0; i<n; i++){
            cout << p[i] + 1 << " \n"[i == n-1];
        }
    }
 
    return 0;
}