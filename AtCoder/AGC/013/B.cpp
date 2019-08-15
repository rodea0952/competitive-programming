#include <bits/stdc++.h>
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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n);
    int sa, sb;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        if(i==0) sa=a, sb=b;
        g[a].eb(b);
        g[b].eb(a);
    }

    list<int> lst;
    lst.push_front(sa), lst.push_back(sb);
    vector<bool> visited(n, false);
    visited[sa]=true, visited[sb]=true;
    queue<int> que;
    que.push(sa);
    while(que.size()){
        int cv=que.front(); que.pop();
        for(int i=0; i<g[cv].size(); i++){
            int nv=g[cv][i];
            if(!visited[nv]){
                visited[nv]=true;
                lst.push_front(nv);
                que.push(nv);
                break;
            }
        }
    }

    int tail=sb;
    que.push(sb);
    while(que.size()){
        int cv=que.front(); que.pop();
        for(int i=0; i<g[cv].size(); i++){
            int nv=g[cv][i];
            if(!visited[nv]){
                tail=nv;
                visited[nv]=true;
                lst.push_back(nv);
                que.push(nv);
                break;
            }
        }
    }

    cout << lst.size() << endl;
    for(auto itr=lst.begin(); itr!=lst.end(); itr++){
        if(*itr==tail) cout << *itr+1 << endl;
        else cout << *itr+1 << " ";
    }
}