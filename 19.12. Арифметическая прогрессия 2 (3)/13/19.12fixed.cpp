/* Исправил
* 19.12. Арифметическая прогрессия 2 (3)
На доске написана некоторая конечная арифметическая прогрессия. Неизвестный злоумышленник, возможно, стер некоторые числа с доски. В результате на доске осталось m чисел a1, a2, …, am. Какую наименьшую длину n могла иметь первоначальная последовательность?
Ввод из файла INPUT.TXT. В первой строке содержится значение m (1 ≤ m ≤ 104). Во второй строке записана последовательность целых чисел a1, a2, …, am (-109 ≤ ai ≤ 109).
Вывод в файл OUTPUT.TXT. В единственной строке выводится наименьшая возможная длина первоначальной последовательности.
Примеры
Ввод 1          Ввод 2
4               2
1 2 4 5         -10 10
Вывод 1         Вывод 2
5               2
Visual Studio Пс-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: program_name input_file output_file" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    int m;
    inputFile >> m;

    vector<int> sequence(m);
    for (int i = 0; i < m; i++) {
        inputFile >> sequence[i];
    }

    sort(sequence.begin(), sequence.end());

    int commonDifference = sequence[1] - sequence[0];
    for (int i = 1; i < m; i++) {
        commonDifference = gcd(commonDifference, sequence[i] - sequence[i - 1]);
    }

    int minLength = (sequence[m - 1] - sequence[0]) / commonDifference + 1;

    outputFile << minLength;

    inputFile.close();
    outputFile.close();

    return 0;
}
