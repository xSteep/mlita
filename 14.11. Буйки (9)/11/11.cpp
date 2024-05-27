#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> buoys(N);
    for (int i = 0; i < N; i++) {
        cin >> buoys[i];
    }

    // Вычисляем среднюю координату всех буйков
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += buoys[i];
    }
    int average = sum / N;

    // Вычисляем сдвиги для каждого буйка
    vector<double> shifts(N);
    for (int i = 0; i < N; i++) {
        shifts[i] = average - buoys[i];
    }

    // Вычисляем сумму сдвигов
    double totalShift = 0;
    for (int i = 0; i < N; i++) {
        totalShift += shifts[i];
    }

    // Выводим результаты
    cout << fixed << setprecision(4) << totalShift << endl;
    for (int i = 0; i < N; i++) {
        cout << fixed << setprecision(7) << buoys[i] + shifts[i] << " ";
    }

    return 0;
}
