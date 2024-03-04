Организовать текстовый файл. Организовать замену символов в файле. "старый" символ и "новый" символ запрашиваются и вводятся с клавиатуры. (создавая новый дополнительный файл).

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char oldChar, newChar;

    cout << "Введите символ для замены: ";
    cin >> oldChar;

    cout << "Введите новый символ: ";
    cin >> newChar;

    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Невозможно открыть файл input.txt "<< endl;
        return 1;
    }

    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cerr << "Невозможно открыть файл output.txt " << endl;
        return 1;
    }

    char c;
    while (inputFile.get(c)) {
        if (c == oldChar) {
            outputFile << newChar;
        }
        else {
            outputFile << c;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Замена успешно выполнена. Результат сохранен в файл 'output.txt' " << endl;

    return 0;
}
