/*
19.10. Магазин (2)
В магазине штучных изделий продают флешки, бляшки, чашки и другие товары. В налоговой инспекции оказались два списка. В первом указано количество проданных товаров каждого вида, а во втором - цены каждого вида товаров. Порядок товаров в списках разный. Добрый и злой инспекторы для начисления налогов желают определить наименьшую и наибольшую возможную выручку от всех проданных товаров.
Ввод. Первая строка файла INPUT.TXT содержит число видов товаров N (1 ≤ N ≤ 50). Во второй строке задаются через пробел целые положительные числа X1, X2,…, XN, определяющие количество каждого вида товара (1 ≤ Xi ≤ 200). В третьей строке задаются через пробел целые положительные числа Y1, Y2,…, YN , определяющие цены каждого вида товара (1 ≤ Yi ≤ 200). Данные по одному и тому же товару в общем случае содержатся в элементах списков X и Y с разными номерами.
Вывод. Результат в файле OUTPUT.TXT в виде двух целых чисел через пробел.
Пример
Ввод
2
5 1
4 7
Вывод
27 39
Visual  Studio 2022 ПС-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N;
    input >> N;

    vector<int> quantities(N);
    vector<int> prices(N);

    for (int i = 0; i < N; i++) {
        input >> quantities[i];
    }

    for (int i = 0; i < N; i++) {
        input >> prices[i];
    }

    sort(quantities.begin(), quantities.end());
    sort(prices.begin(), prices.end());

    int minRevenue = 0;
    int maxRevenue = 0;

    for (int i = 0; i < N; i++) {
        minRevenue += quantities[i] * prices[N - i - 1];
        maxRevenue += quantities[i] * prices[i];
    }

    output << minRevenue << " " << maxRevenue << endl;

    input.close();
    output.close();

    return 0;
}
