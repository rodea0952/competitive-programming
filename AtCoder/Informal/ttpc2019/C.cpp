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

    int n, x; cin>>n>>x;
    int sum = 0;
    int cnt = 0;
    vector<int> a(n);
    vector<int> index;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] == -1){
            cnt++;
            index.emplace_back(i);
        }
        else sum ^= a[i];
    }

    int need = x ^ sum;

    if(x < need){
        if(cnt < 2){
            cout << -1 << endl;
            return 0;
        }
        else{
            for(int i=0; i<index.size(); i++){
                if(i == 0) a[index[i]] = x;
                else if(i == 1){
                    a[index[i]] = need ^ x;
                    if(x < (need ^ x)){
                        cout << -1 << endl;
                        return 0;
                    }
                }
                else a[index[i]] = 0;
            }
        }
    }
    else{
        if(cnt < 1 && need != 0){
            cout << -1 << endl;
            return 0;
        }
        else{
            for(int i=0; i<index.size(); i++){
                if(i == 0) a[index[i]] = need;
                else a[index[i]] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
}