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

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int ng = 0, ok = n;
    while(ok - ng > 1){
        int mid = (ng + ok) / 2;

        bool valid = true;
        stack<P> st;
        for(int i=0; i+1<n; i++){
            if(a[i] >= a[i+1]){
                while(st.size() && !(st.top().first <= a[i+1])) st.pop();
                if(st.size() && st.top().first == a[i+1]) st.top().second++;
                else st.emplace(a[i+1], 1);

                while(st.top().second == mid){
                    int digit = st.top().first;
                    if(digit == 1) {valid = false; break;}
                    st.pop();
                    if(st.size() && st.top().first == digit - 1) st.top().second++;
                    else st.emplace(digit-1, 1);
                }

                if(!valid) break;
            }
        }

        if(valid) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}