#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
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

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }

    bool cmp_y(const Point &a, const Point &b) {
        return !equals(a.Y, b.Y) ? a.Y < b.Y : a.X < b.X;
    }
}

Polygon convexHull(Polygon ps){
    int n = ps.size();
    sort(ps.begin(), ps.end(), cmp_y);
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
    int n; cin>>n;
    Polygon pol;
    while(n--){
        double x, y; cin>>x>>y;
        pol.emplace_back(x, y);
    }

    Polygon ans = convexHull(pol);

    cout << ans.size() << endl;
    for(auto i:ans){
        cout << i.X << " " << i.Y << endl;
    }
}