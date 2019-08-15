#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll n, w; cin>>n>>w;
    ll wei1;
    vector<int> val1, val2, val3, val4;
    for(int i=0; i<n; i++){
        int wei, val; cin>>wei>>val;
        if(i == 0){
            wei1=wei;
            val1.push_back(val);
            continue;
        }

        if(wei == wei1) val1.push_back(val);
        else if(wei == wei1 + 1) val2.push_back(val);
        else if(wei == wei1 + 2) val3.push_back(val);
        else val4.push_back(val);
    }

    ll wei1_size=val1.size(), wei2_size=val2.size(), wei3_size=val3.size(), wei4_size=val4.size();
    sort(val1.begin(), val1.end(), greater<int>());
    sort(val2.begin(), val2.end(), greater<int>());
    sort(val3.begin(), val3.end(), greater<int>());
    sort(val4.begin(), val4.end(), greater<int>());

    vector<int> val1_sum(wei1_size+10, 0), val2_sum(wei2_size+10, 0), val3_sum(wei3_size+10, 0), val4_sum(wei4_size+10, 0);
    for(int i=1; i<=wei1_size; i++){
        if(i == 1) val1_sum[i] = val1[i-1];
        else val1_sum[i] = val1_sum[i-1] + val1[i-1];
    }
    for(int i=1; i<=wei2_size; i++){
        if(i == 1) val2_sum[i] = val2[i-1];
        else val2_sum[i] = val2_sum[i-1] + val2[i-1];
    }
    for(int i=1; i<=wei3_size; i++){
        if(i == 1) val3_sum[i] = val3[i-1];
        else val3_sum[i] = val3_sum[i-1] + val3[i-1];
    }
    for(int i=1; i<=wei4_size; i++){
        if(i == 1) val4_sum[i] = val4[i-1];
        else val4_sum[i] = val4_sum[i-1] + val4[i-1];
    }

    int ans=0;
    for(ll i=0; i<=wei1_size; i++){
        for(ll j=0; j<=wei2_size; j++){
            for(ll k=0; k<=wei3_size; k++){
                for(ll l=0; l<=wei4_size; l++){
                    if((wei1)*i + (wei1+1LL)*j + (wei1+2LL)*k + (wei1+3LL)*l <= w){
                        ans = max(ans, val1_sum[i]+val2_sum[j]+val3_sum[k]+val4_sum[l]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}