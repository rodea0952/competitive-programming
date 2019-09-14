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

const int MAX_N = 200010;

bool isPrime[MAX_N];
void eratosthenes(int n){
    for(int i=0; i<=n; i++) isPrime[i] = true;
    isPrime[0] = false, isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=2; i*j<=n; j++){
                isPrime[i*j] = false;
            }
        }
    }
}

int fun_hash(int i){
    int num = i;

    while(!(1 <= num && num <= 9)){
        int num2 = num;
        int sum = 0;
        while(0 < num2){
            sum += (num2 % 10);
            num2 /= 10;
        }
        num = sum;
    }

    return num;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, n; cin>>k>>n;

    eratosthenes(n);

    vector<int> prime;
    for(int i=k; i<=n; i++){
        if(isPrime[i]) prime.emplace_back(i);
    }

    vector<P> hashed_prime;
    for(auto i : prime){
        hashed_prime.emplace_back(fun_hash(i), i);
    }

    int m = hashed_prime.size();

    if(m == 1){
        cout << hashed_prime[0].second << endl;
        return 0;
    }

    int max_len = 1;
    for(int i=0; i<m; i++){
        set<int> st;
        st.emplace(hashed_prime[i].first);
        for(int j=i+1; j<m; j++){
            if(st.find(hashed_prime[j].first) != st.end()){
                chmax(max_len, j - i);
                break;
            }

            if(j == m - 1){
                chmax(max_len, m - i);
            }

            st.emplace(hashed_prime[j].first);
        }
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        set<int> st;
        st.emplace(hashed_prime[i].first);
        for(int j=i+1; j<m; j++){
            if(st.find(hashed_prime[j].first) != st.end()){
                if(j - i == max_len){
                    chmax(ans, hashed_prime[i].second);
                }
                break;
            }
        
            if(j == m - 1){
                if(m - i == max_len){
                    chmax(ans, hashed_prime[i].second);
                }
            }

            st.emplace(hashed_prime[j].first);
        }
    }

    cout << ans << endl;
    
    return 0;
}