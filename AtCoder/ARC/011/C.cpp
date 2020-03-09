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

vector<int> dijkstra(int s, vector<vector<P>> &G){
    int n = G.size();
    vector<int> dist(n, inf), pre(n, -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top(); que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = nxt;
            
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                pre[nv] = cv;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return pre;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string f, l; cin>>f>>l;
    int n; cin>>n;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    if(f == l){
        cout << 0 << endl;
        cout << f << endl;
        cout << l << endl;
        return 0;
    }

    map<string, int> s2node;
    map<int, string> node2s;
    s2node[f] = 0, node2s[0] = f;
    int cnt = 1;
    for(int i=0; i<n; i++){
        if(s2node.find(s[i]) == s2node.end()){
            s2node[s[i]] = cnt;
            node2s[cnt] = s[i];
            cnt++;
        }
    }
    s2node[l] = cnt, node2s[cnt] = l;
    cnt++;

    vector<vector<P>> G(cnt);
    for(auto i : s2node){
        for(auto j : s2node){
            string si = i.first, sj = j.first;
            int dif = 0;
            for(int k=0; k<si.size(); k++){
                if(si[k] != sj[k]) dif++;
            }
            if(dif == 1){
                G[i.second].emplace_back(j.second, 1);
            }
        }
    }

    auto pre = dijkstra(0, G);

    if(pre[cnt - 1] == -1){
        cout << -1 << endl;
        return 0;
    }

    vector<string> ans;
    for(int i=cnt-1; i!=-1; i=pre[i]){
        ans.emplace_back(node2s[i]);
    }

    cout << ans.size() - 2 << endl;
    reverse(all(ans));
    for(auto i : ans) cout << i << endl;

    return 0;
}