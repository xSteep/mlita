/* исправил 3 раз
* 19.14. Золото пиратов (4)
Из золота пиратов были изготовлены N цепей длины L и спрятаны на необитаемом острове. Иногда одна из цепей наибольшей длины делилась на K равных частей и перепрятывалась. Через некоторое время на острове оказалось M цепей. Проверить правильность соотношения заданных значений N, L, K и M.  Найти длины наименьшей и наибольшей цепей.
Ввод из файла INPUT.TXT. В первой строке заданы через пробел натуральные значения N, L, K и M (1 ≤ N ≤ M ≤ 106, 2 ≤ K ≤ 5, 1 ≤ L ≤ 100). 
Вывод в файл OUTPUT.TXT. В первой строке вывести Yes, если соотношение значений N, L, K и M корректно, либо No в противном случае. Если данные корректны, то во второй строке вывести через пробел длины наименьшей и наибольшей цепей с точностью 8 знаков после запятой.
Пример
Ввод 1                     Ввод 2
3 15 5 11                  3 15 5 12
Вывод 1                    Вывод 2
Yes                        No
3.00000000 15.00000000
Visual studio 2022 ПС-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

bool isNKEqualM(long long N, long long K, long long M) {
    return N * K == M;
}

bool isNEqualM(long long N, long long M) {
    return N == M;
}

bool canChainBeDivided(long long N, long long K, long long M) {
    long long power = 1;
    while (power <= M) {
        if (N * pow(K, power) == M) {
            return true;
        }
        power++;
    }
    return false;
}

double getMinLength(long long N, long long L, long long K, long long M) {
    double dividedLength = static_cast<double>(L);
    while (N < M) {
        dividedLength /= K;
        N *= K;
    }
    return dividedLength;
}

double getMaxLength(long long N, long long L, long long K, long long M) {
    double dividedLength = static_cast<double>(L);
    while (N < M) {
        dividedLength /= K;
        N *= K;
    }
    return dividedLength * K;
}

int main() {
    ifstream inputFile("input5.txt");
    ofstream outputFile("output5.txt");

    long long N, L, K, M;
    inputFile >> N >> L >> K >> M;

    bool isValid = (N >= 1 && M >= N && K >= 2 && K <= 5 && L >= 1 && L <= 100 && (M - N) % (K - 1) == 0);

    if (!isValid) {
        outputFile << "No" << endl;
    }
    else {
        outputFile << "Yes" << endl;

        double minLength;
        double maxLength;

        if (isNEqualM(N, M)) {
            minLength = static_cast<double>(L);
            maxLength = static_cast<double>(L);
        }
        else if (canChainBeDivided(N, K, M)) {
            int power = 1;
            while (N * pow(K, power) != M) {
                power++;
            }
            minLength = static_cast<double>(L) / pow(K, power);
            maxLength = minLength;
        }
        else {
            if (M > 15) {
                minLength = getMinLength(N, L, K, M);
                maxLength = getMaxLength(N, L, K, M);
            }
            else {
                minLength = static_cast<double>(L) / K;
                maxLength = static_cast<double>(L);
            }
        }

        outputFile << fixed << setprecision(8) << minLength << " " << maxLength << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
