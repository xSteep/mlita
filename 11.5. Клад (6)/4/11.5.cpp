/*
* 11.5. Клад (6)
Кладоискатели обнаружили люк в подземелье с сокровищами, закрытый неподъемной квадратной чугунной плитой. К счастью, плита имеет сквозную трещину, разделяющую ее на две части, которые не лежат полностью одна внутри другой. Трещина представляет собой ломаную без самопересечений и самокасаний. В распоряжении кладоискателей имеется лебедка. Мощности лебедки хватает на то, чтобы двигать в определенном направлении без вращения каждую из частей, не поднимая ее, но не всю плиту целиком. Требуется по форме трещины определить, могут ли кладоискатели освободить люк.
Ввод из файла INPUT.TXT. В первой строке находится число N, задающее количество вершин ломаной. Следующие N строк содержат пары целых чисел - координаты вершин (Xi, Yi). Ломаная получается путем последовательного соединения точек в данном порядке. Направление обхода вершин ломаной может быть произвольным. Точки (X1, Y1) и (XN , YN) лежат на одной или разных сторонах квадрата, остальные точки ломаной – внутри квадрата. 
Ограничения: 3 ≤ N ≤ 100; -100 ≤ Xi ≤ 100; -100 ≤ Yi ≤ 100.
Вывод в файл OUTPUT.TXT. Выводится единственная строка со значением Yes или No – возможность либо невозможность разъединения квадрата путем перемещения его частей по плоскости без вращений.
Примеры 
Ввод 1    Ввод 2  Ввод 3  Ввод 3
5         4       5       6
0 0       3 0     -1 3    0 4
0 1       4 1     0 3     1 3
1 1       1 1     1 0     1 2
2 2       2 0     -3 0    2 1
2 0               -3 1    2 2
                          3 4
Вывод 1   Вывод 2 вывод 3 вывод 4
Yes       No      No      yes
Visual Studio 2022 ПС-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <vector>

struct Point {
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool isClockwise(const std::vector<Point>& points) {
    int sum = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        const Point& current = points[i];
        const Point& next = points[(i + 1) % n];
        sum += (next.x - current.x) * (next.y + current.y);
    }

    return sum < 0;
}

bool canSeparateSquare(const std::vector<Point>& points) {
    int n = points.size();

    bool clockwise = isClockwise(points);

    for (int i = 1; i < n - 1; i++) {
        std::vector<Point> upper, lower;

        for (int j = 0; j < n; j++) {
            if (j < i)
                upper.push_back(points[j]);
            else if (j > i)
                lower.push_back(points[j]);
        }

        if (isClockwise(upper) != clockwise && isClockwise(lower) != clockwise)
            return false;
    }

    return true;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

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
