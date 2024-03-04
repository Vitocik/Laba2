Организовать файл целых чисел. Определить наибольший элемент файла среди элементов файла номера которых кратны трем.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ofstream out; // поток для записи
    out.open("number.txt"); // открываем файл для записи
    if (out.is_open())
    {
        out << "2 7 5 -3 6 9 -3 0 12" << std::endl;
    }
    out.close();
    ifstream inputFile("number.txt");
    if (!inputFile.is_open()) {
        cerr << "Не удается открыть файл." << endl;
        return 1;
    }

    int number;
    vector<int> numbers;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    int maxNumber = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        if ((i + 1) % 3 == 0) {
            if (numbers[i] > maxNumber) {
                maxNumber = numbers[i];
            }
        }
    }

    cout << "Наибольший элемент среди чисел с номерами, кратными трем: " << maxNumber << endl;

    return 0;
}
