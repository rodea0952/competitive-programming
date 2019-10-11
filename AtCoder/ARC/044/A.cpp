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

    ll n; cin>>n;

    if(n == 1){
        cout << "Not Prime" << endl;
        return 0;
    }

    bool prime = true;

    for(ll i=2; i*i<=n; i++){
        if(n % i == 0) prime = false;
    }

    if(prime){
        cout << "Prime" << endl;
        return 0;
    }

    int digit1 = n % 10;
    if(digit1 % 2 != 0 && digit1 != 5){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }

        if(sum % 3 != 0){
            cout << "Prime" << endl;
        }
        else{
            cout << "Not Prime" << endl;
        }
        return 0;
    }

    cout << "Not Prime" << endl;
    
    return 0;
}
