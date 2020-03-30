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

    int n, l; cin>>n>>l;
    vector<int> x(n);
    vector<char> d(n);
    for(int i=0; i<n; i++) cin>>x[i]>>d[i];

    vector<int> div;
    for(int i=0; i+1<n; i++){
        if(d[i] == 'L' && d[i+1] == 'R'){
            div.emplace_back(x[i]);
        }
    }
    div.emplace_back(l);

    int idx = 0;
    ll ans = 0;
    for(int i=0; i<div.size(); i++){
        int tail = div[i];
        vector<int> Ridx, Lidx;
        while(idx < n && x[idx] <= tail){
            if(d[idx] == 'R') Ridx.emplace_back(x[idx]);
            else Lidx.emplace_back(x[idx]);
            idx++;
        }

        ll Rmove = 0;
        if(Ridx.size()){
            // まず 'R' を動かす
            int goal;
            if(Lidx.size() == 0) goal = l;
            else goal = Lidx[0] - 1;
            for(int j=Ridx.size()-1; j>=0; j--){
                Rmove += (goal - Ridx[j]);
                goal--;
            }

            if(Lidx.size()){
                goal = Lidx[0];
                for(int j=0; j<Lidx.size(); j++){
                    Rmove += (Lidx[j] - goal);
                    goal++;
                }
            }
        }

        ll Lmove = 0;
        if(Lidx.size()){
            // まず 'L' を動かす
            int goal;
            if(Ridx.size() == 0) goal = 1;
            else goal = Ridx.back() + 1;
            for(int j=0; j<Lidx.size(); j++){
                Lmove += (Lidx[j] - goal);
                goal++;
            }

            if(Ridx.size()){
                goal = Ridx.back();
                for(int j=Ridx.size()-1; j>=0; j--){
                    Lmove += (goal - Ridx[j]);
                    goal--;
                }
            }
        }

        ans += max(Rmove, Lmove);
    }

    cout << ans << endl;

    return 0;
}
