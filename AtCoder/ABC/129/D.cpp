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
    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++){
        cin>>s[i];
    }

    vector<vector<int>> W(h + 10, vector<int>(w + 10, 0));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '.') W[i + 1][j + 1] = W[i + 1][j] + 1;
        }

        int Wmax = W[i + 1][w];
        for(int j=w-1; j>=0; j--){
            if(j + 1 < w && s[i][j] == '.' && s[i][j + 1] == '#') Wmax = W[i + 1][j + 1];
            W[i + 1][j + 1] = Wmax;
        }
    }

    vector<vector<int>> H(h + 10, vector<int>(w + 10, 0));
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(s[j][i] == '.') H[j + 1][i + 1] = H[j][i + 1] + 1;
        }

        int Hmax = H[h][i + 1];
        for(int j=h-1; j>=0; j--){
            if(j + 1 < h && s[j][i] == '.' && s[j + 1][i] == '#') Hmax = H[j + 1][i + 1];
            H[j + 1][i + 1] = Hmax;
        }
    }

    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '#') continue;
            ans = max(ans, W[i + 1][j + 1] + H[i + 1][j + 1] - 1);
        }
    }

    cout << ans << endl;
}
