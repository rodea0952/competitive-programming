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

    string s; cin>>s;
    ll k; cin>>k;
    ll n = s.size();

    set<int> st;
    for(int i=0; i<n; i++){
        st.emplace(s[i] - 'a');
    }

    ll ans = 0;
    if(st.size() == 1){
        if(n % 2 == 0){
            ans += n * k / 2;
        }
        else{
            ans += n * ((k + 1) / 2);
            if(k % 2 == 1){
                ans -= n / 2 + 1;
            }
        }
    }
    else{
        bool valid = false;
        if(s[0] == s[n-1]){
            ll head = 0;
            char h = s[0];
            for(int i=0; i<n; i++){
                if(h != s[i]) break;
                head++;
            }
            ll tail = 0;
            char t = s[n-1];
            for(int i=n-1; i>=0; i--){
                if(t != s[i]) break;
                tail++;
            }

            if(head % 2 && tail % 2){
                valid = true;
            }
        }

        ll cnt = 0;
        for(int i=1; i<n; i++){
            if(s[i-1] == s[i]){
                s[i] = '@';
                cnt++;
            }
        }

        ans += cnt * k;
        if(valid) ans += (k - 1);
    }

    cout << ans << endl;

    return 0;
}