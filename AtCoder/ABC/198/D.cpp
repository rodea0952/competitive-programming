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

    vector<string> s(3);
    for(int i=0; i<3; i++) cin>>s[i];

    vector<char> alp;
    for(int i=0; i<3; i++){
        for(auto j:s[i]) alp.emplace_back(j);
    }

    sort(all(alp));
    alp.erase(unique(all(alp)), alp.end());

    if(10 < alp.size()){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<int> perm(10, 0);
    iota(all(perm), 0);

    do{
        map<char, int> alp2num;
        for(int i=0; i<alp.size(); i++){
            alp2num[alp[i]] = perm[i];
        }

        vector<ll> n(3, 0);
        bool valid = true;
        for(int i=0; i<3; i++){
            if(alp2num[s[i].front()] == 0){
                valid = false;
                break;
            }

            for(auto j:s[i]){
                n[i] += alp2num[j];
                n[i] *= 10;
            }
            n[i] /= 10;
        }

        if(valid && n[0] + n[1] == n[2]){
            for(int i=0; i<3; i++){
                cout << n[i] << endl;
            }
            return 0;
        }

    }while(next_permutation(all(perm)));

    cout << "UNSOLVABLE" << endl;

    return 0;
}