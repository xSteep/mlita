#include <iostream>
#include <fstream>

int getLastDigit(int a, int n) {
    int lastDigit = a % 10; 

    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * lastDigit) % 10;
        }
        lastDigit = (lastDigit * lastDigit) % 10;
        n /= 2;
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: program_name input_file output_file" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    int a, n;
    inputFile >> a >> n;

    int lastDigit = getLastDigit(a, n);

    outputFile << lastDigit << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
