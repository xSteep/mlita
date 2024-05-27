#include <iostream>
#include <fstream>
#include <vector>

struct Point {
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

int orientation(const Point& p1, const Point& p2, const Point& p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0)
        return 0;  // точки коллинеарны
    return (val > 0) ? 1 : -1;  // возвращает 1, если против часовой стрелки, и -1 в противном случае
}

bool canSeparateSquare(const std::vector<Point>& points) {
    const Point& p1 = points[0];
    const Point& p2 = points[1];

    int orientationValue = orientation(p1, p2, points[2]);

    int n = points.size();
    for (int i = 2; i < n - 1; i++) {
        const Point& current = points[i];
        const Point& next = points[i + 1];
        Point vector = { current.x - p2.x, current.y - p2.y };
        if (orientation(p1, p2, current) != orientationValue || orientation(p1, p2, vector) == 0 || orientation(p1, p2, next) == 0)
            return false;
    }

    return true;
}

int main() {
    std::ifstream input("input2.txt");
    std::ofstream output("output2.txt");

    int n;
    input >> n;

    if (n < 3 || n > 100) {
        output << "No" << std::endl;
        return 0;
    }

    std::vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        input >> x >> y;

        if (x < -100 || x > 100 || y < -100 || y > 100) {
            output << "No" << std::endl;
            return 0;
        }

        points.emplace_back(x, y);
    }

    bool possible = canSeparateSquare(points);
    output << (possible ? "Yes" : "No") << std::endl;

    return 0;
}
