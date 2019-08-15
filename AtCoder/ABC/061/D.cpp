#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;
typedef tuple<int, int, ll> T;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<T> edge(2010);
vector<bool> negative(1010);
vector<ll> dis(1010, INF);

ll shortest_path(){
    dis[0]=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            int crt_v, nxt_v;
            ll cost;
            tie(crt_v, nxt_v, cost)=edge[j];
            //cout << crt_v << " " << nxt_v << " " << cost << endl;

            if(dis[crt_v] != INF && dis[nxt_v] > dis[crt_v] + cost){
                dis[nxt_v] = dis[crt_v] + cost;
            }
        }
    }
    return -dis[n-1];
}

void find_negative_loop(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int crt_v, nxt_v;
            ll cost;
            tie(crt_v, nxt_v, cost)=edge[j];
            //cout << crt_v << " " << nxt_v << " " << cost << endl;

            if(dis[crt_v] != INF && dis[nxt_v] > dis[crt_v] + cost){
                dis[nxt_v] = dis[crt_v] + cost;
                negative[nxt_v]=true;
            }

            if(negative[crt_v]){
                negative[nxt_v]=true;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        ll c; 
        cin>>a>>b>>c;
        a--, b--;
        edge[i]=T(a, b, -c);
    }

    ll ans=shortest_path();
    find_negative_loop();

    if(negative[n-1]){
        cout << "inf" << endl;
    }
    else{
        cout << ans << endl;
    }
}