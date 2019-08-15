#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n; cin>>n;
    queue<string> que;

    que.push("a");
    que.push("b");
    que.push("c");

    for(int i=1; i<n; i++){
        for(int j=0; j<pow(3, i); j++){
            string x = que.front();
            que.pop();
            string a2 = x + "a", b2 = x + "b", c2 = x + "c";
            que.push(a2), que.push(b2), que.push(c2); 
        }
    }
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }
}