#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int a, b, c, d, e; cin>>a>>b>>c>>d>>e;
    set<int> s;
    int a1=a+b+c, a2=a+b+d, a3=a+b+e, a4=a+c+d, a5=a+c+e;
    int a6=a+d+e, a7=b+c+d, a8=b+c+e, a9=b+d+e, a10=c+d+e;
    s.insert(a1), s.insert(a2), s.insert(a3), s.insert(a4), s.insert(a5);
    s.insert(a6), s.insert(a7), s.insert(a8), s.insert(a9), s.insert(a10);

    priority_queue<int> que;
    for(auto x : s) que.push(x);
    que.pop(), que.pop();
    cout << que.top() << endl;
}