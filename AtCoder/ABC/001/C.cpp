#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    double deg, dis; cin>>deg>>dis;
    
    deg/=10;

    string s;
    if(deg < 11.25) s="N";
    else if(deg < 33.75) s="NNE";
    else if(deg < 56.25) s="NE";
    else if(deg < 78.75) s="ENE";
    else if(deg < 101.25) s="E";
    else if(deg < 123.75) s="ESE";
    else if(deg < 146.25) s="SE";
    else if(deg < 168.75) s="SSE";
    else if(deg < 191.25) s="S";
    else if(deg < 213.75) s="SSW";
    else if(deg < 236.25) s="SW";
    else if(deg < 258.75) s="WSW";
    else if(deg < 281.25) s="W";
    else if(deg < 303.75) s="WNW";
    else if(deg < 326.25) s="NW";
    else if(deg < 348.75) s="NNW";
    else s="N";

    dis/=60;
    dis*=10;
    double dis2=(int)(dis+0.5);
    dis2/=10;

    int n;
    if(dis2 <= 0.2) s="C", n=0;
    else if(dis2 <= 1.5) n=1;
    else if(dis2 <= 3.3) n=2;
    else if(dis2 <= 5.4) n=3;
    else if(dis2 <= 7.9) n=4;
    else if(dis2 <= 10.7) n=5;
    else if(dis2 <= 13.8) n=6;
    else if(dis2 <= 17.1) n=7;
    else if(dis2 <= 20.7) n=8;
    else if(dis2 <= 24.4) n=9;
    else if(dis2 <= 28.4) n=10;
    else if(dis2 <= 32.6) n=11;
    else n=12;

    cout << s << " " << n << endl;
}