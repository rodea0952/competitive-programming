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
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> d(m);
    vector<int> numDark(n, -1);
    for(int i=0; i<m; i++){
        cin>>d[i];
        d[i]--;
        numDark[d[i]] = i;
    }

    vector<vector<int>> v(n, vector<int>(k));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin>>v[i][j];
            v[i][j]--;
        }
    }

    vector<int> dist((1 << m), 1e9);
    dist[(1 << m) - 1] = 0;
    queue<int> que;
    que.emplace((1 << m) - 1);
    while(que.size()){
        int cbit = que.front();
        que.pop();

        for(int i=0; i<k; i++){
            int nbit = 0;
            for(int j=0; j<m; j++){
                if(cbit & (1 << j)){
                    int nxtRoom = v[d[j]][i];

                    if(numDark[nxtRoom] < 0) continue;

                    nbit |= (1 << numDark[nxtRoom]);
                }
            }

            if(dist[cbit] + 1 < dist[nbit]){
                dist[nbit] = dist[cbit] + 1;
                que.emplace(nbit);
            }
        }
    }

    cout << dist[0] << endl;
}