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

const int MAX_N = 1000010;

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

    eratosthenes(1000000);

    vector<int> cnt(1000001, 1);
    for(int i=2; i<=1000000; i++){
        if(isPrime[i]){
            cnt[i] = cnt[i-2] + isPrime[i-2];
        }
    }

    int n; cin>>n;
    int sum = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        x = cnt[x];
        sum ^= x;
    }

    if(sum == 0) cout << "Ai" << endl;
    else cout << "An" << endl;
}