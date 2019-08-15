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
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int asum = accumulate(a.begin(), a.end(), 0);

    vector<int> div;
    for(int i=1; i*i<=asum; i++){
        if(asum % i == 0){
            div.emplace_back(i);
            div.emplace_back(asum / i);
        }
    }

    sort(div.begin(), div.end(), greater<int>());

    for(auto i:div){
        vector<P> divmod;
        for(int j=0; j<n; j++){
            divmod.emplace_back(a[j] % i, j);
        }
        sort(divmod.begin(), divmod.end());

        ll summod = 0;
        vector<bool> checked(n, false);
        for(int j=0; j<n; j++){
            int num, id;
            tie(num, id) = divmod[j];
            summod += num;
            if(k < summod){
                summod -= num;
                break;
            }
            checked[id] = true;
        }

        for(int j=0; j<n; j++){
            if(!checked[j]){
                int rest = i - a[j] % i;
                summod -= rest;
            }
        }

        if(0 <= summod && summod % i == 0){
            cout << i << endl;
            return 0;
        }
    }
}