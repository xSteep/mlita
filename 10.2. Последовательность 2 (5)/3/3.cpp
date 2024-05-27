/* Исправил второй раз
*
10.2. Последовательность 2 (5)
Каждый член последовательности десятичных цифр d1, d2, d3..., начиная с четвёртого, вычисляется по формуле di  = (di-3 + di-2  + di-1) mod x. По заданным d1, d2, d3, x найти N-й член последовательности.
Ввод из файла INPUT.TXT. В первой строке находятся d1, d2, d3, x, разделённые пробелами, во второй - число N.
Вывод в файл OUTPUT.TXT. Вывести одну цифру - dN.
Ограничения: 1 ≤ N ≤ 1018, 2 ≤  x ≤ 10, время 1 с.
Примеры
Ввод 1    Ввод 2
1 4 8 10  5 5 5 10
4         1000000000000000
Вывод 1   Вывод 2
3         5
Visual Studio 2022 Федосеев Максим ПС-23
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B, int mod) {
    int n = A.size();
    int m = B[0].size();
    int k = A[0].size();

    Matrix result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                result[i][j] = (result[i][j] + (A[i][l] * B[l][j]) % mod) % mod;
            }
        }
    }

    return result;
}

Matrix matrixPower(const Matrix& A, long long power, int mod) {
    int n = A.size();

    Matrix result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    Matrix base = A;
    long long p = power;

    while (p > 0) {
        if (p & 1) {
            result = multiply(result, base, mod);
        }

        base = multiply(base, base, mod);
        p >>= 1;
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: program_name input_file output_file" << endl;
        return 1;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    int d1, d2, d3, x;
    inputFile >> d1 >> d2 >> d3 >> x;

    long long N;
    inputFile >> N;

    if (N <= 3) {
        outputFile << d1 << " " << d2 << " " << d3 << endl;
    }
    else {
        Matrix transitionMatrix = { {1, 1, 1}, {1, 0, 0}, {0, 1, 0} };

        Matrix poweredMatrix = matrixPower(transitionMatrix, N - 3, x);

        int result = (poweredMatrix[0][0] * d3 + poweredMatrix[0][1] * d2 + poweredMatrix[0][2] * d1) % x;

        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
