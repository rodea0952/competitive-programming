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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, int, int, int> T;
typedef tuple<int, int, int> T2;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int x, y, z, k; cin>>x>>y>>z>>k;
    vector<ll> a(x), b(y), c(z);
    for(int i=0; i<x; i++) cin>>a[i];
    for(int i=0; i<y; i++) cin>>b[i];
    for(int i=0; i<z; i++) cin>>c[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    priority_queue<T> que;
    que.push(T(a[0] + b[0] + c[0], 0, 0, 0));

    vector<ll> ans;
    map<T2, bool> visited;
    for(int i=0; i<k; i++){
        ll sum;
        int ai, bi, ci;
        tie(sum, ai, bi, ci) = que.top();
        que.pop();

        ans.eb(sum);

        if(ai + 1 < x && !visited[T2(ai+1, bi, ci)]){
            que.push(T(a[ai+1] + b[bi] + c[ci], ai+1, bi, ci));
            visited[T2(ai+1, bi, ci)] = true;
        }

        if(bi + 1 < y && !visited[T2(ai, bi+1, ci)]){
            que.push(T(a[ai] + b[bi+1] + c[ci], ai, bi+1, ci));
            visited[T2(ai, bi+1, ci)] = true;
        }
        
        if(ci + 1 < z && !visited[T2(ai, bi, ci+1)]){
            que.push(T(a[ai] + b[bi] + c[ci+1], ai, bi, ci+1));
            visited[T2(ai, bi, ci+1)] = true;
        }
    }

    for(auto i:ans){
        cout << i << endl;
    }
}