/*
* 14.11. Буйки (9)
На пляже перпендикулярно береговой линии размечены прямолинейными буйками
параллельные плавательные дорожки. Они получились разной ширины. Требуется сдвинуть
некоторые из буйков без изменения порядка их следования так, чтобы дорожки оказались равной
ширины, а сумма сдвигов была минимальной.
Ввод. Первая строка содержит число буйков N (2 ≤ N ≤ 400). Во второй строке указываются
координаты буйков X1 < X2 <…< XN (-10000 ≤ X i ≤ 10000) в виде целых чисел по оси X,
совпадающей с береговой линией.
Вывод. В первой строке выводится с точностью до 4 знаков действительное число S –
минимальная общая длина требуемых сдвигов. Во второй строке выводятся через пробел с
точностью до 7 знаков новые координаты буйков. Если имеется несколько вариантов решения,
вывести любое из них.
Пример
Ввод
4
-2 2 6 9
Вывод
1.0000
-2.0000000 1.6666667 5.3333333 9.0000000
Visual Studio 2022 ПС-23 Федосеев Максим
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> buoys(N);
    for (int i = 0; i < N; i++) {
        cin >> buoys[i];
    }

    double average_width = static_cast<double>(buoys.back() - buoys.front()) / (N - 1);

    vector<double> shifts(N, 0.0);
    for (int i = 1; i < N - 1; i++) {
        double target_position = buoys.front() + i * average_width;
        shifts[i] = target_position - buoys[i];
    }

    cout << fixed << setprecision(4);
    cout << -accumulate(shifts.begin(), shifts.end(), 0.0) << endl;

    cout << fixed << setprecision(7);
    for (int i = 0; i < N; i++) {
        cout << buoys[i] + shifts[i] << " ";
    }
    cout << endl;

    return 0;
}
