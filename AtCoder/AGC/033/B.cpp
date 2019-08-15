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
    int h, w, n; cin>>h>>w>>n;
    int sy, sx; cin>>sy>>sx;
    sy--, sx--;
    string s, t; cin>>s>>t;

    bool valid = true;
    int cy = sy, cx = sx;

    // go up
    for(int i=0; i<n; i++){
        if(s[i] == 'U') cy--;
        if(cy < 0){
            valid = false;
            break;
        }
        if(t[i] == 'D'){
            cy++;
            chmin(cy, h - 1);
        }
    }

    // go down
    cy = sy, cx = sx;
    for(int i=0; i<n; i++){
        if(s[i] == 'D') cy++;
        if(h <= cy){
            valid = false;
            break;
        }
        if(t[i] == 'U'){
            cy--;
            chmax(cy, 0);
        }
    }

    // go right
    cy = sy, cx = sx;
    for(int i=0; i<n; i++){
        if(s[i] == 'R') cx++;
        if(w <= cx){
            valid = false;
            break;
        }
        if(t[i] == 'L'){
            cx--;
            chmax(cx, 0);
        }
    }

    // go left
    cy = sy, cx = sx;
    for(int i=0; i<n; i++){
        if(s[i] == 'L') cx--;
        if(cx < 0){
            valid = false;
            break;
        }
        if(t[i] == 'R'){
            cx++;
            chmin(cx, w - 1);
        }
    }

    if(valid) cout << "YES" << endl;
    else cout << "NO" << endl;
}