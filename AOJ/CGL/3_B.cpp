#include <iostream>
#include <complex>
#include <utility>
#include <vector>
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

// ベクトルと点の位置関係
int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool isConvex(Polygon pol){
    int n = pol.size();

    for(int i=0; i<n; i++){
        if(ccw(pol[i], pol[(i+1)%n], pol[(i+2)%n]) == CLOCKWISE){
            return false;
        }
    }

    return true;
}

int main(){
    int n; cin>>n;
    Polygon pol;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        pol.emplace_back(x, y);
    }

    cout << isConvex(pol) << endl;
}