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
    vector<string> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    vector<int> p2(n, 0), p5(n, 0);
    for(int i=0; i<n; i++){
        if(count(all(s[i]), '.')){
            while(s[i].back() == '0') s[i].pop_back();
            if(s[i].back() == '.') s[i].pop_back();
        }
    
        ll cur;
        if(s[i].find('.') != string::npos){
            int idx = s[i].find('.');
            string head = s[i].substr(0, idx), tail = s[i].substr(idx + 1);
            cur = stoll(head + tail);
            for(int j=tail.size(); j<9; j++) cur *= 10;
        }
        else{
            cur = stoll(s[i]);
            for(int j=0; j<9; j++) cur *= 10;
        }

        while(cur % 2 == 0){
            p2[i]++;
            cur /= 2;
        }

        while(cur % 5 == 0){
            p5[i]++;
            cur /= 5;
        }
    }

    vector<vector<int>> cnt(60, vector<int>(30, 0));
    for(int i=0; i<n; i++){
        cnt[p2[i]][p5[i]]++;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        int need2 = max(18 - p2[i], 0);
        int need5 = max(18 - p5[i], 0);

        for(int j=need2; j<60; j++){
            for(int k=need5; k<30; k++){
                ans += cnt[j][k];
            }
        }

        if(9 <= p2[i] && 9 <= p5[i]) ans--;
    }

    cout << ans / 2 << endl;

    return 0;
}