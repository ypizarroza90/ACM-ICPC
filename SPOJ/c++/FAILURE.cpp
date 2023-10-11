#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 100000

template<class T> void checkmin(T &a, T b) {
	if (b < a)
		a = b;
}
template<class T> void checkmax(T &a, T b) {
	if (b > a)
		a = b;
}
struct point {
	int x, y;
};
bool cmpX(const point &a, const point &b) {
	return a.x < b.x;
}
bool cmpY(const point &a, const point &b) {
	return a.y < b.y;
}

int point_x[MAX], point_y[MAX];
bool div_x[MAX];

void buildTree(int left, int right, point points[]) {
    	if (left >= right)
    		return;
    	int mid = (left + right) >> 1;

    	int minx = INT_MAX;
    	int maxx = INT_MIN;
    	int miny = INT_MAX;
    	int maxy = INT_MIN;
    	for (int i = left; i < right; i++) {
    		checkmin(minx, points[i].x);
    		checkmax(maxx, points[i].x);
    		checkmin(miny, points[i].y);
    		checkmax(maxy, points[i].y);
    	}
    	div_x[mid] = (maxx - minx) >= (maxy - miny);
    	nth_element(points + left, points + mid, points + right, div_x[mid] ? cmpX : cmpY);

    	point_x[mid] = points[mid].x;
    	point_y[mid] = points[mid].y;

    	if (left + 1 == right)
    		return;
    	buildTree(left, mid, points);
    	buildTree(mid + 1, right, points);
    }

i64 closestD;
int closestN;

void findNearestNeighbour(int left, int right, int x, int y) {
    	if (left >= right)
    		return;
    	int mid = (left + right) >> 1;
    	int dx = x - point_x[mid];
    	int dy = y - point_y[mid];
    	long long d = dx * (long long) dx + dy * (long long) dy;
    	if (closestD > d && d) {
    		closestD = d;
    		closestN = mid;
    	}
    	if (left + 1 == right)
    		return;

    	int delta = div_x[mid] ? dx : dy;
    	long long delta2 = delta * (long long) delta;
    	int l1 = left;
    	int r1 = mid;
    	int l2 = mid + 1;
    	int r2 = right;
    	if (delta > 0)
    		swap(l1, l2), swap(r1, r2);

    	findNearestNeighbour(l1, r1, x, y);
    	if (delta2 < closestD)
    		findNearestNeighbour(l2, r2, x, y);
    }

    int findNearestNeighbour(int n, int x, int y) {
    	closestD = LLONG_MAX;
    	findNearestNeighbour(0, n, x, y);
    	return closestN;
    }

int main() {

	int cas, n;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d",&n);
		vector<point> points(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d",&points[i].x, &points[i].y);
		}
		buildTree(0, n, &(vector<point>(points)[0]));

		for (int i = 0; i < n; i++) {
			findNearestNeighbour(n, points[i].x, points[i].y);
			printf("%lld\n", closestD);
		}
	}
	return 0;
}
