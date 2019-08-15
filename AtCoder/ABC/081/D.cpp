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
    int n; cin>>n;
    vector<int> a(n);
    int amin=1e9, amax=-1e9;
    int minid, maxid;
    for(int i=0; i<n; i++){
        cin>>a[i];

        if(a[i] < amin){
            amin = a[i];
            minid = i;
        }

        if(amax < a[i]){
            amax = a[i];
            maxid = i;
        }
    }

    if(0 <= amin){
        cout << n-1 << endl;
        for(int i=1; i<n; i++){
            cout << i << " " << i+1 << endl;
        }
    }
    else if(amax < 0){
        cout << n-1 << endl;
        for(int i=n; i>1; i--){
            cout << i << " " << i-1 << endl;
        }
    }
    else{
        int cnt=0;
        vector<P> ans;
        if(-amin < amax){
            for(int i=0; i<n; i++){
                if(a[i] < 0){
                    cnt++;
                    ans.eb(P(maxid+1, i+1));
                }
            }

            cout << n-1+cnt << endl;
            for(auto i:ans){
                cout << i.fs << " " << i.sc << endl;
            }
            for(int i=1; i<n; i++){
                cout << i << " " << i+1 << endl;
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(0 < a[i]){
                    cnt++;
                    ans.eb(P(minid+1, i+1));
                }
            }

            cout << n-1+cnt << endl;
            for(auto i:ans){
                cout << i.fs << " " << i.sc << endl;
            }
            for(int i=n; i>1; i--){
                cout << i << " " << i-1 << endl;
            }
        }
    }
}