/*
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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: program_name input_file output_file" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    int m;
    input >> m;

    vector<int> numbers(m);
    for (int i = 0; i < m; i++) {
        input >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int minDifference = numbers[1] - numbers[0];
    for (int i = 2; i < m; i++) {
        minDifference = min(minDifference, numbers[i] - numbers[i - 1]);
    }

    int n = 1;
    while (numbers[m - 1] - (n - 1) * minDifference > numbers[0]) {
        n++;
    }

    output << n << endl;

    input.close();
    output.close();

    return 0;
}

