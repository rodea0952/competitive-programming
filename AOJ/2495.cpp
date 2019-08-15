#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <complex>

const double pi = acos(-1);

using namespace std;
typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b))< EPS)

double norm(Vector a) {
	return a.X * a.X + a.Y * a.Y;
}

double dot(Vector a, Vector b) {
	return a.X* b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b) {
	return a.X* b.Y - a.Y * b.X;
}

double abs(Vector a) {
	return sqrt(norm(a));
}

int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return 1;
	if (cross(a, b) < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;
	if (norm(a) < norm(b)) return -2;
	return 0;
}

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.second - l.first, p - l.first) / abs(l.first - l.second));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.second - s.first, p - s.first) < 0.0) return abs(p - s.first);
    if(dot(s.first - s.second, p - s.second) < 0.0) return abs(p - s.second);
    return getDistanceLP(s, p);
}

pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.first);
    Vector e = (l.second - l.first) / abs(l.second - l.first);

    if(equals(getDistanceLP(l, c.first), c.second)){
        return make_pair(pr, pr);
    }

    double base = sqrt(c.second * c.second - norm(pr - c.first));
    return make_pair(pr - e * base, pr + e * base);
}

double areaCP(Circle c, Polygon pol){
    double S = 0;
    double r = c.second;
    int n = pol.size();
    for(int i=0; i<n; i++){
        pol[i] -= c.first;
    }

    for(int i=0; i<n; i++){
        if(abs(pol[i] * pol[(i+1)%n]) < EPS) continue;
        double d = arg(pol[(i+1)%n] / pol[i]);
        S += r * r * d / 2.0;

        if(getDistanceSP(Segment(pol[i], pol[(i+1)%n]), Point(0, 0)) < r - EPS){
            pair<Point, Point> cps = getCrossPoints(Circle(Point(0, 0), r), Line(pol[i], pol[(i+1)%n]));
            Point a, b;
            if(ccw(pol[i], pol[(i+1)%n], cps.first) == 0 && ccw(pol[i], pol[(i+1)%n], cps.second) == 0){
                a = cps.first, b = cps.second;
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.first)){
                a = cps.first, b = pol[(i+1)%n];
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.second)){
                a = pol[i], b = cps.second;
            }
            else{
                a = pol[i], b = pol[(i+1)%n];
            }

            if(abs(a * b) < EPS) continue;
            d = arg(b / a);
            S += cross(a, b) / 2.0 - r * r * d / 2.0;
        }
    }

    return S;
}

signed main() {
	int n;
	cin >> n;
	double r; cin >> r;

	double ans = 0;

	Polygon pol;
	
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		pol.emplace_back(x, y);
	}

	double s[110];
	s[0] = 0;
	int rr = (int)r;
	for (int i = 1; i <= rr; i++) {
		double ii = i;
		Circle cir = Circle(Point(0, 0), ii);
		s[i] = areaCP(cir, pol);
	}

	for (int i = 1; i <= r; i++) {
		double r1 = i - 1, r2 = i;
		double ring = r2 * r2 * pi - r1 * r1 * pi;
		double diff = s[i] - s[i - 1];
		if (i % 2 == 0) { // blue
			ans += ring - diff;
		}
		else {
			ans += diff;
		}
	}
	printf("%.10f\n", ans);
}

