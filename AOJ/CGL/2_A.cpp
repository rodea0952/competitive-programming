#include <iostream>
#include <complex>
#include <utility>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()

#define eps (1e-10)
#define equals(a, b) (fabs((a) - (b)) < eps)

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0);
}

bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0);
}

int main(){
    int q; cin>>q;
    while(q--){
        double x0, y0, x1, y1, x2, y2, x3, y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;

        Vector V0 = Point(x0, y0) - Point(x1, y1);
        Vector V1 = Point(x2, y2) - Point(x3, y3);

        int ans = 0;
        if(isParallel(V0, V1)){
            ans = 2;
        }
        else if(isOrthogonal(V0, V1)){
            ans = 1;
        }

        cout << ans << endl;
    }
}