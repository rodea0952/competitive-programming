#include <bits/stdc++.h>
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using Point = complex<double>;
using Vector = complex<double>;
using Segment = pair<Point, Point>;
using Line = pair<Point, Point>;
using Polygon = vector<Point>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

Polygon convexHull(Polygon ps){
    int n = ps.size();
    sort(ps.begin(), ps.end());
    int k = 0;
    Polygon convex(n * 2);
    for(int i=0; i<n; i++){
        while(k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--){
        while(k > t && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

int main(){
    int h, w; cin>>h>>w;
    vector<string> c(h);
    Polygon pol;
    for(int i=0; i<h; i++){
        cin>>c[i];
        for(int j=0; j<w; j++){
            if(c[i][j] == 'B'){
                pol.emplace_back(i, j);
            }
        }
    }

    pol = convexHull(pol);

    int n = pol.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Point p1 = pol[i];
            Point p2 = pol[j];
            chmax(ans, (int)(abs(p1.X - p2.X) + abs(p1.Y - p2.Y)));
        }
    }

    cout << ans << endl;
}