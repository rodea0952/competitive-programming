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
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<char> t(q), d(q);
    for(int i=0; i<q; i++) cin>>t[i]>>d[i];

    // [lb, ub)
    // go left
    int lb=0, ub=n;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        int cv = mid;
        char cc = s[mid];

        for(int i=0; i<q; i++){
            if(t[i] == cc){
                if(d[i] == 'R'){
                    cv++;
                    if(n - 1 < cv) break;
                }
                else{
                    cv--;
                    if(cv < 0) break;
                }

                cc = s[cv];
            }
        }

        if(cv < 0) lb = mid;
        else ub = mid;
    }

    int lcnt = lb + 1;
    //cout << lcnt << endl;

    // go right
    lb=0, ub=n;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        int cv = mid;
        char cc = s[mid];

        for(int i=0; i<q; i++){
            if(t[i] == cc){
                if(d[i] == 'R'){
                    cv++;
                    if(n - 1 < cv) break;
                }
                else{
                    cv--;
                    if(cv < 0) break;
                }

                cc = s[cv];
            }
        }

        if(n - 1 < cv) ub = mid;
        else lb = mid;
    }

    int rcnt = (n - (lb + 1));
    //cout << rcnt << endl;

    cout << n - lcnt - rcnt << endl;
}