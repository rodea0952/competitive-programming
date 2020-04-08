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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    stack<P> st;
    for(int i=0; i<n; i++){
        if(i == 0){
            if(a[i] == 0){
                st.emplace(0, 1);
            }
            else{
                st.emplace(1, 1);
            }
        }
        else if(i % 2 == 0){
            int pre_color = st.top().first;
            if(pre_color == a[i]){
                int num = st.top().second; st.pop();
                st.emplace(a[i], num + 1);
            }
            else{
                st.emplace(a[i], 1);
            }
        }
        else{
            int pre_color = st.top().first;
            if(pre_color == a[i]){
                int num = st.top().second; st.pop();
                st.emplace(a[i], num + 1);
            }
            else{
                int num = st.top().second; st.pop();
                int num2 = 0;
                if(st.size()){
                    num2 += st.top().second; st.pop();
                }
                st.emplace(a[i], num + num2 + 1);
            }
        }
    }

    int ans = 0;
    while(st.size()){
        int color, num;
        tie(color, num) = st.top(); st.pop();
        if(color == 0) ans += num;
    }

    cout << ans << endl;

    return 0;
}