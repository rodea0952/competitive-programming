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

const int MAX_N = 10000010;
bool isPrime[MAX_N];
void eratosthenes(int n){
    for(int i=0; i<=n; i++) isPrime[i] = true;
    isPrime[0] = false, isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=2; i*j<=n; j++){
                isPrime[i*j] = false;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    eratosthenes(10000005);

    vector<int> ans(10000005);
    ans[13] = 13;
    for(int i=14; i<=10000000; i++){
        ans[i] = ans[i-1];
        if(isPrime[i] && isPrime[i-2] && isPrime[i-6] && isPrime[i-8]) ans[i] = i;
    }

    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        cout << ans[n] << endl;
    }

    return 0;
}