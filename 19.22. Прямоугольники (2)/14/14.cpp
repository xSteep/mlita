/*
* 19.22. Прямоугольники (2)
На клетчатом листе бумаги дан квадрат размером N×N (0 < N ≤ 20). В нем нарисовано несколько прямоугольников со сторонами, параллельными сторонам квадрата или составляющими часть стороны квадрата. Каждый прямоугольник включает только целые клетки. Различные прямоугольники не накладываются друг на друга и могут касаться только углами, но не сторонами. Квадрат представлен двумерным массивом A, в котором Aij = 1, если клетка (i, j) принадлежит какому-либо прямоугольнику, и Aij =  0 в противном случае. Написать программу, определяющую число прямоугольников.
Ввод. В первой строке файла INPUT.TXT содержится значение N. Каждая из последующих N строк содержит ровно N символов, задающих по строкам клетки квадрата.
Вывод. В единственной строке файла OUTPUT.TXT вывести одно число - возможное количество прямоугольников.
Пример
Ввод
5
11011
11000
11011
00011
11100
Вывод
4
Visual Studio ПС-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int countRectangles(const vector<vector<int>>& grid, int N) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                if ((i == 0 || grid[i - 1][j] == 0) && (j == 0 || grid[i][j - 1] == 0)) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: ./program input_file output_file" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    ifstream input(inputFile);
    ofstream output(outputFile);

    int N;
    input >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char cell;
            input >> cell;
            grid[i][j] = (cell == '1') ? 1 : 0;
        }
    }

    int rectangleCount = countRectangles(grid, N);

    output << rectangleCount << endl;

    return 0;
}
