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
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int N, A, B, C, D;
int a[110], b[110], c[110], d[110];
vector<int> v = {1, 2, 3}, tmp;
bool visited[110][110][110][110], memo[110][110][110][110];

bool dp(int i, int j, int k, int l){
    if(i == A && j == B && k == C && l == D) return true;
    if(visited[i][j][k][l]) return memo[i][j][k][l];

    visited[i][j][k][l] = true;

    tmp.clear();
    tmp = {a[i], b[j], c[k]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp) memo[i][j][k][l] |= dp(i+1, j+1, k+1, l);

    tmp.clear();
    tmp = {a[i], b[j], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp) memo[i][j][k][l] |= dp(i+1, j+1, k, l+1);

    tmp.clear();
    tmp = {a[i], c[k], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp) memo[i][j][k][l] |= dp(i+1, j, k+1, l+1);

    tmp.clear();
    tmp = {b[j], c[k], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp) memo[i][j][k][l] |= dp(i, j+1, k+1, l+1);

    return memo[i][j][k][l];
}

void restore(int i, int j, int k, int l){
    if(i == A && j == B && k == C && l == D) return;

    tmp.clear();
    tmp = {a[i], b[j], c[k]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp && dp(i+1, j+1, k+1, l)){
        cout << 4 << endl;
        restore(i+1, j+1, k+1, l);
        return;
    }

    tmp.clear();
    tmp = {a[i], b[j], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp && dp(i+1, j+1, k, l+1)){
        cout << 3 << endl;
        restore(i+1, j+1, k, l+1);
        return;
    }

    tmp.clear();
    tmp = {a[i], c[k], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp && dp(i+1, j, k+1, l+1)){
        cout << 2 << endl;
        restore(i+1, j, k+1, l+1);
        return;
    }

    tmp.clear();
    tmp = {b[j], c[k], d[l]};
    sort(tmp.begin(), tmp.end());
    if(v == tmp && dp(i, j+1, k+1, l+1)){
        cout << 1 << endl;
        restore(i, j+1, k+1, l+1);
        return;
    }
}

int main(){
    cin>>N>>A>>B>>C>>D;
    for(int i=0; i<A; i++) cin>>a[i];
    for(int i=0; i<B; i++) cin>>b[i];
    for(int i=0; i<C; i++) cin>>c[i];
    for(int i=0; i<D; i++) cin>>d[i];

    if((A + B + C + D) % 3 == 0 && (A + B + C + D) / 3 == N && dp(0, 0, 0, 0)){
        cout << "Yes" << endl;
        restore(0, 0, 0, 0);
    }
    else{
        cout << "No" << endl;
    }
}