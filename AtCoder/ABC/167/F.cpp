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

    vector<P> l, r;
    for(int i=0; i<n; i++){
        int mi = 0, sum = 0;
        for(auto j:s[i]){
            if(j == '(') sum++;
            else sum--;
            chmin(mi, sum);
        }
        
        if(0 <= sum){
            l.emplace_back(mi, sum);
        }
        else{
            reverse(all(s[i]));
            mi = 0, sum = 0;
            for(auto j:s[i]){
                if(j == ')') sum++;
                else sum--;
                chmin(mi, sum);
            }
            r.emplace_back(mi, sum);
        }
    }

    sort(all(l), greater<P>());
    sort(all(r), greater<P>());

    int curl = 0;
    bool valid = true;
    for(auto i:l){
        int mi, sum;
        tie(mi, sum) = i;

        if(curl + mi < 0) valid = false;
        curl += sum;
    }

    int curr = 0;
    for(auto i:r){
        int mi, sum;
        tie(mi, sum) = i;
        
        if(curr + mi < 0) valid = false;
        curr += sum;
    }

    if(curl != curr) valid = false;

    cout << (valid ? "Yes" : "No") << endl;

    return 0;
}