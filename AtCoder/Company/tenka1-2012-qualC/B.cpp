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
    int n = s.size();

    int S = 0, H = 0, D = 0, C = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'S' || s[i] == 'H' || s[i] == 'D' || s[i] == 'C'){
            char alp = s[i];

            i++;
            string t;
            while(i < n && s[i] != 'S' && s[i] != 'H' && s[i] != 'D' && s[i] != 'C'){
                t += s[i];
                i++;
            }
            i--;

            if(t == "10" || t == "J" || t == "Q" || t == "K" || t == "A"){
                if(alp == 'S') S++;
                else if(alp == 'H') H++;
                else if(alp == 'D') D++;
                else C++;
            }

            cnt++;
        }

        if(S == 5 || H == 5 || D == 5 || C == 5) break;
    }

    vector<string> ans;
    int cnt2 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'S' || s[i] == 'H' || s[i] == 'D' || s[i] == 'C'){
            char alp = s[i];

            i++;
            string t;
            while(i < n && s[i] != 'S' && s[i] != 'H' && s[i] != 'D' && s[i] != 'C'){
                t += s[i];
                i++;
            }
            i--;

            if(t == "10" || t == "J" || t == "Q" || t == "K" || t == "A"){
                if(alp == 'S'){
                    if(S != 5) ans.emplace_back('S' + t);
                }
                else if(alp == 'H'){
                    if(H != 5) ans.emplace_back('H' + t);
                }
                else if(alp == 'D'){
                    if(D != 5) ans.emplace_back('D' + t);
                }
                else{
                    if(C != 5) ans.emplace_back('C' + t);
                }
            }
            else{
                ans.emplace_back(alp + t);
            }

            cnt2++;
        }

        if(cnt2 == cnt) break;
    }

    if(ans.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    for(auto i : ans){
        cout << i;
    }
    cout << endl;

    return 0;
}