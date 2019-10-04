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

    while(1){
        int n; cin>>n;
        if(n == 0) break;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin>>s[i];

        int ans = -1;
        for(int k=1; k<=60; k++){
            set<string> st;
            for(int j=0; j<n; j++){
                int sz = s[j].size();
                string t;
                t += s[j][0];
                for(int l=1; l<sz; l++){
                    if(t.size() == k) break;
                    if(s[j][l-1] == 'a') t += s[j][l];
                    if(s[j][l-1] == 'i') t += s[j][l];
                    if(s[j][l-1] == 'u') t += s[j][l];
                    if(s[j][l-1] == 'e') t += s[j][l];
                    if(s[j][l-1] == 'o') t += s[j][l];
                }

                st.emplace(t);
            }

            if(st.size() == n){
                ans = k;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}