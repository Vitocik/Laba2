Дан файл f, компоненты которого являются целыми числами. Получить в файле g все компоненты файла f, являющиеся точными квадратами.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool isPerfectSquare(int number) {
    int kor = sqrt(number);
    return kor * kor == number;
}

int main() {
    setlocale(LC_ALL, "RU");
    ofstream File("text.txt");
    if (File.is_open())
    {
        File << "49 25 65 12 16 81 56 73 100 36 55" << endl;
    }
    
    File.close();

    ifstream inputFile("text.txt");
    ofstream outputFile("kvadr.txt");
    int number;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (inputFile >> number) {
            if (isPerfectSquare(number)) {
                outputFile << number << endl;
            }
        }
        inputFile.close();
        outputFile.close();
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }

    return 0;
}

