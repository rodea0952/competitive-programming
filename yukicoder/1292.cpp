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

    string s; cin>>s;

    // UorD := 三角形が上向きか下向きか
    // (a, b, c) := (0, 1, 2)
    int UorD = 0, bottom = 2;
    int cx = 0, cy = 0;
    set<P> point;
    point.emplace(cx, cy);

    for(auto i:s){
        if(i == 'a'){
            if(bottom == 0){
                if(UorD == 0) cy--;
                else cy++;
            }
            else if(bottom == 1){
                bottom = 2;
                cx--;
                if(UorD == 0) cy++;
                else cy--;
            }
            else{
                bottom = 1;
                cx++;
                if(UorD == 0) cy++;
                else cy--;
            }
        }
        else if(i == 'b'){
            if(bottom == 0){
                bottom = 2;
                cx++;
                if(UorD == 0) cy++;
                else cy--;
            }
            else if(bottom == 1){
                if(UorD == 0) cy--;
                else cy++;
            }
            else{
                bottom = 0;
                cx--;
                if(UorD == 0) cy++;
                else cy--;
            }
        }
        else{
            if(bottom == 0){
                bottom = 1;
                cx--;
                if(UorD == 0) cy++;
                else cy--;
            }
            else if(bottom == 1){
                bottom = 0;
                cx++;
                if(UorD == 0) cy++;
                else cy--;
            }
            else{
                if(UorD == 0) cy--;
                else cy++;
            }
        }

        UorD ^= 1;
        point.emplace(cx, cy);
    }

    cout << point.size() << endl;

    return 0;
}