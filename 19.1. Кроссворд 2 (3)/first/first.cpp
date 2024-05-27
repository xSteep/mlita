/* Исправил
9.1. Кроссворд 2 (3)
Кроссворд размещен в квадрате. Строки и столбцы квадрата нумеруются сверху вниз и слева направо, начиная с 1. Поля для слов располагаются горизонтально либо вертикально и задаются путем указания координат начальной и конечной клеток. Какая-либо сортировка при задании полей отсутствует. Два пересекающихся слова могут располагаться как на одной горизонтали либо вертикали, так и перпендикулярно друг другу. Подсчитать количество занятых клеток кроссворда.
Ввод. В первой строке файла INPUT.TXT заданы размер квадрата M (1 ≤ M ≤ 50) и количество слов кроссворда N (1 ≤ N ≤ 20). В следующих N строках указываются координаты (ai, bi) начальной и конечной клеток очередного слова (1 ≤ ai, bi ≤ M).
Вывод. В единственной строке выходного файла OUTPUT.TXT должно содержаться общее количество занятых клеток кроссворда.
Пример
Ввод
10 2
2 3 3 3
1 3 4 3
Вывод
4
Visual Studio 2022 ПС-23 Федосеев Максим
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Word {
    int startRow;
    int startCol;
    int endRow;
    int endCol;
};

int countOccupiedCells(int gridSize, const vector<Word>& words) {
    vector<vector<bool>> crossword(gridSize, vector<bool>(gridSize, false));

    for (const auto& word : words) {
        if (word.startRow == word.endRow) {
            for (int col = min(word.startCol, word.endCol); col <= max(word.startCol, word.endCol); ++col) {
                crossword[word.startRow - 1][col - 1] = true;
            }
        }
        else if (word.startCol == word.endCol) {
            for (int row = min(word.startRow, word.endRow); row <= max(word.startRow, word.endRow); ++row) {
                crossword[row - 1][word.startCol - 1] = true;
            }
        }
        else {
            // добавил для учета пересечений которые расположены не на одной горизонтали или вертикали
            for (int row = min(word.startRow, word.endRow); row <= max(word.startRow, word.endRow); ++row) {
                for (int col = min(word.startCol, word.endCol); col <= max(word.startCol, word.endCol); ++col) {
                    crossword[row - 1][col - 1] = true;
                }
            }
        }
    }

    int occupiedCount = 0;
    for (const auto& row : crossword) {
        for (bool cell : row) {
            if (cell) {
                ++occupiedCount;
            }
        }
    }

    return occupiedCount;
}

int main() {
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");

    int gridSize, wordCount;
    inputFile >> gridSize >> wordCount;

    vector<Word> words(wordCount);
    for (int i = 0; i < wordCount; ++i) {
        inputFile >> words[i].startRow >> words[i].startCol >> words[i].endRow >> words[i].endCol;
    }

    int occupiedCells = countOccupiedCells(gridSize, words);
    outputFile << occupiedCells << endl;

    return 0;
}
