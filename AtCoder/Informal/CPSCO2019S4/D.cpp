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
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> b;
    for(int i=0; i<n; i++){
        int cnt = 1;
        while(i + 1 < n && a[i] == a[i+1]){
            cnt++;
            i++;
        }

        b.eb(cnt);
    }

    int ng = 0, ok = *max_element(b.begin(), b.end());
    while(ok - ng > 1){
        int mid = (ng + ok) / 2;

        priority_queue<int> que;
        for(int i=0; i<b.size(); i++){
            que.push(b[i]);
        }

        bool valid = false;
        for(int i=0; i<k; i++){
            int num = que.top();
            que.pop();

            if(num == 1){
                cout << 1 << endl;
                return 0;
            }

            if(mid < num){
                que.push(1);
                que.push(mid);
                que.push(num - 1 - mid);
            }
            else{
                valid = true;
                break;
            }
        }

        int qmax = que.top();

        if(qmax <= mid || valid){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }

    cout << ok << endl;
}