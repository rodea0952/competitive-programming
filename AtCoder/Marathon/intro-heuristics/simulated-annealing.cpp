// ref: https://atcoder.jp/contests/intro-heuristics/submissions/15983533
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
#include <chrono>
using namespace std;
using namespace chrono;

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

// 0 以上 UINT_MAX(0xffffffff) 以下の整数をとる乱数 https://ja.wikipedia.org/wiki/Xorshift
static uint32_t randXor(){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

// 0 以上 1 未満の小数をとる乱数
static double rand01(){
    return (randXor() + 0.5) * (1.0 / UINT_MAX);
}

const int NUM_TYPES = 26;

static int getFullScore(const int d, const vector<int> &c, const vector<int> &t, const vector<vector<int>> &s){
    int score = 0;
    vector<int> last(NUM_TYPES, -1);
    for(int i=0; i<d; i++){
        score += s[i][t[i]];
        last[t[i]] = i;
        for(int j=0; j<NUM_TYPES; j++){
            score -= c[j] * (i - last[j]);
        }
    }

    return score;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int d; cin >> d;
    vector<int> c(NUM_TYPES);
    for(int i=0; i<26; i++) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(NUM_TYPES));
    for(int i=0; i<d; i++){
        for(int j=0; j<26; j++) cin >> s[i][j];
    }

    vector<int> t(d);
    for(int i=0; i<d; i++){
        t[i] = i % NUM_TYPES;
    }

    // 焼きなまし法
    auto start_clock = system_clock::now();
    int score = getFullScore(d, c, t, s);  // 現在のスコア
    int best_score = INT_MIN;              // 最高スコア
    vector<int> best_t;                    // 最高スコアのときの t

    const static double START_TEMP = 1500; // 開始時の温度
    const static double END_TEMP   =  100; // 終了時の温度
    const static double END_TIME   =  1.8; // 終了時間（秒）
    double time = 0.0;                     // 経過時間（秒）

    while(time < END_TIME){
        const double progress_ratio = time / END_TIME; // 進捗 開始時が 0.0、終了時が 1.0
        const double temp = START_TEMP + (END_TEMP - START_TEMP) * progress_ratio;

        if(rand01() > 0.5){
            // 近傍 1：rand_d 日目のコンテストを rand_t に変える
            const int rand_d = randXor() % d;
            const int rand_t = randXor() % NUM_TYPES;
            const int pre_t = t[rand_d];
            int delta_score = 0;

            delta_score -= getFullScore(d, c, t, s);
            t[rand_d] = rand_t;
            delta_score += getFullScore(d, c, t, s);
            const double probability = exp(delta_score / temp); // 焼きなまし法の遷移確率
        
            if(probability > rand01()){
                score += delta_score;
                if(score > best_score){
                    best_score = score;
                    best_t = t;
                }
            }
            else{
                t[rand_d] = pre_t;
            }
        }
        else{
            // 近傍 2：d0 日目のコンテストと d1 日目のコンテストを交換
            const int diff = randXor() % min(d - 1, 10) + 1; // d0 と d1 は最大 10 日差
            const int d0 = randXor() % (d - diff);
            const int d1 = d0 + diff;
            int delta_score = 0;

            delta_score -= getFullScore(d, c, t, s);
            swap(t[d0], t[d1]);
            delta_score += getFullScore(d, c, t, s);
            const double probability = exp(delta_score / temp); // 焼きなまし法の遷移確率

            if(probability > rand01()){
                score += delta_score;
                if(score > best_score){
                    best_score = score;
                    best_t = t;
                }
            }
            else{
                swap(t[d0], t[d1]);
            }
        }

        time = (duration_cast<microseconds>(system_clock::now() - start_clock).count() * 1e-6);
    }

    for(int i=0; i<d; i++){
        cout << t[i] + 1 << endl;
    }

    cerr << "best_score: " << max(0, best_score + 1000000) << endl;

    return 0;
}