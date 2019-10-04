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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1){
        int h, w; cin>>h>>w;
        if(h == 0) break;

        int dist = h * h + w * w;

        int mindist = inf;

        int ansh = inf;
        int answ = inf;

        // h
        for(int i=1; i<=150; i++){
            // w
            for(int j=i+1; j<=150; j++){
                int cdist = i * i + j * j;

                if(dist < cdist){
                    if(mindist == cdist){
                        if(i < ansh){
                            ansh = i, answ = j;
                        }
                    }
                    else if(cdist < mindist){
                        mindist = cdist;
                        ansh = i, answ = j;
                    }
                }
                else if(dist == cdist){
                    if(h < i){
                        ansh = i, answ = j;
                        goto END;
                    }
                }
            }
        }

        END:;
        cout << ansh << " " << answ << endl;
    }

    return 0;
}