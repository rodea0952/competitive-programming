// #define _GLIBCXX_DEBUG // for STL debug (optional)
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
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

const int DAY = 365;
const int CONT = 26;

struct Solver {
    int D, C[CONT], S[DAY][CONT], ans[DAY];
    ll score;
    set<int> schedules[CONT];

    Solver() {
        fill(ans, ans + DAY, -1);
    }
    
    void read_input() {
        scanf("%d", &D);
        for(int i=0; i<CONT; i++) {
            scanf("%d", &C[i]);
        }
        for(int i=0; i<D; i++) {
            for(int j=0; j<CONT; j++) {
                scanf("%d", &S[i][j]);
            }
        }

        for(int i=0; i<CONT; i++) {
            schedules[i].emplace(-1);
            schedules[i].emplace(D);
        }
    }

    ll calc_score(bool store=true) {
        ll res = 0;
        int last[CONT] = {};
        for(int i=0; i<D; i++) {
            res += S[i][ ans[i] ];
            last[ ans[i] ] = i+1;
            for(int j=0; j<CONT; j++) {
                res -= C[j] * (i+1 - last[j]);
            }
        }
        if(store) score = res;
        return max(0LL, res);
    }

    void update(int day, int contest) {
        int pre_contest = ans[day];
        ans[day] = contest;

        // 削除
        {
            score -= S[day][pre_contest];
            auto ptr = schedules[pre_contest].lower_bound(day);
            ll d0 = day - *prev(ptr);
            ll d1 = *next(ptr) - *prev(ptr);
            ll d2 = *next(ptr) - day;
            cout << d0 << " " << d1 << " " << d2 << endl; 
            score += d0 * (d0 - 1) / 2 * C[pre_contest];
            score -= d1 * (d1 - 1) / 2 * C[pre_contest];
            score += d2 * (d2 - 1) / 2 * C[pre_contest];
            schedules[pre_contest].erase(day);
        }
        // 追加
        {
            score += S[day][contest];
            schedules[contest].emplace(day);
            auto ptr = schedules[contest].lower_bound(day);
            ll d0 = day - *prev(ptr);
            ll d1 = *next(ptr) - *prev(ptr);
            ll d2 = *next(ptr) - day;
            cout << d0 << " " << d1 << " " << d2 << endl; 
            score -= d0 * (d0 - 1) / 2 * C[contest];
            score += d1 * (d1 - 1) / 2 * C[contest];
            score -= d2 * (d2 - 1) / 2 * C[contest];
        }
    }
};

int main() {
    Solver solver;
    solver.read_input();
    for(int i=0; i<solver.D; i++) {
        int t; scanf("%d", &t);
        solver.ans[i] = --t;
        solver.schedules[t].emplace(i);
    }
    solver.calc_score();

    int Q; scanf("%d", &Q);
    while(Q--) {
        int d, q; scanf("%d%d", &d, &q);
        d--; q--;
        solver.update(d, q);
        printf("%lld\n", solver.score);
    }
    return 0;
}
