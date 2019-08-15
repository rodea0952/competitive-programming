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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll n; cin>>n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    ll sum=n*(n-1)*(n-2)/6;
    ll acute_angle_cnt=0, right_angle_cnt=0, obtuse_angle_cnt=0;

    for(int i=0; i<n; i++){
        vector<double> angle;
        
        for(int j=0; j<n; j++){
            if(i==j) continue;

            angle.push_back(atan2(y[j]-y[i], x[j]-x[i]));
        }

        sort(angle.begin(), angle.end());

        // 偏角を [-pi, pi] と [pi, 3pi] にする
        // 前者からは [0, pi] を、後者からは [pi, 2pi] を選ぶことができ、簡単に書ける
        for(int j=0; j<n-1; j++){
            angle.push_back(angle[j]+2*pi);
        }

        // -pi <= v_j <= pi より
        for(int j=0; j<n-1; j++){
            right_angle_cnt += lower_bound(angle.begin(), angle.end(), angle[j]+pi/2+eps) - lower_bound(angle.begin(), angle.end(), angle[j]+pi/2-eps);
            obtuse_angle_cnt += lower_bound(angle.begin(), angle.end(), angle[j]+pi) - lower_bound(angle.begin(), angle.end(), angle[j]+pi/2+eps);
        }
    }

    acute_angle_cnt = sum - (right_angle_cnt + obtuse_angle_cnt);

    cout << acute_angle_cnt << " " << right_angle_cnt << " " << obtuse_angle_cnt << endl;
}

