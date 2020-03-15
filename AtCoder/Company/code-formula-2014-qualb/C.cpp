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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string a, b; cin>>a>>b;
    if(a.size() > 6){
        string adif, bdif;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]){
                adif += a[i];
                bdif += b[i];
            }
        }

        if(adif.size() > 6){
            cout << "NO" << endl;
            return 0;
        }

        while(adif.size() < 6){
            adif += "@";
            bdif += "@";
        }

        a = adif, b = bdif;
    }

    int n = a.size();
    for(int i=0; i<n; i++){
        for(int ii=0; ii<n; ii++){
            for(int j=0; j<n; j++){
                for(int jj=0; jj<n; jj++){
                    for(int k=0; k<n; k++){
                        for(int kk=0; kk<n; kk++){
                            if(i == ii) continue;
                            if(j == jj) continue;
                            if(k == kk) continue;

                            string ca = a;
                            swap(ca[i], ca[ii]);
                            swap(ca[j], ca[jj]);
                            swap(ca[k], ca[kk]);

                            if(ca == b){
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}