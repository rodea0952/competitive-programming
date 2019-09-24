#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, T &b) {a = max(a, b);}
template <class T> inline T chmin(T &a, T &b) {a = min(a, b);}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, r; cin>>n>>r;
    vector<int> id2p(n);
    for(int i=0; i<n; i++){
        int p; cin>>p;
        id2p[i] = --p;
    }

    vector<bool> visited(n, false);
    vector<int> groupNum;
    for(int i=0; i<n; i++){
        int cur = i;
        int cnt = 0;
        while(!visited[cur]){
            visited[cur] = true;
            cur = id2p[cur];
            cnt++;
        }

        if(cnt) groupNum.emplace_back(cnt);
    }

    r = min(r, n - r);
    bitset<150001> dp;
    dp[0] = 1;
    for(auto i : groupNum){
        dp |= (dp << i);
    }

    cout << (dp[r] ? "Yes" : "No") << endl;
}