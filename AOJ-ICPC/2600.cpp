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

int main(){
    int n, w, h; cin>>n>>w>>h;
    vector<int> imosw(w+1, 0), imosh(h+1, 0);
    for(int i=0; i<n; i++){
        int x, y, d; cin>>x>>y>>d;
        int minx = max(0, x - d);
        int maxx = min(w - 1, x + d - 1);
        imosw[minx]++;
        imosw[maxx + 1]--;

        int miny = max(0, y - d);
        int maxy = min(h - 1, y + d - 1);
        imosh[miny]++;
        imosh[maxy + 1]--;
    }

    bool validw = true;
    for(int i=0; i<w; i++){
        if(imosw[i] <= 0) validw = false;
        imosw[i + 1] += imosw[i];
    }

    bool validh = true;
    for(int i=0; i<h; i++){
        if(imosh[i] <= 0) validh = false;
        imosh[i + 1] += imosh[i];
    }

    if(validw || validh){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}