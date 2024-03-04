Дано 2 файла вещественных чисел а1.txt и а2.txt. Найти количество нулевых
элементов в двух файлов.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Открываем файлы для чтения
    ifstream file1("a1.txt");
    ifstream file2("a2.txt");

    float number;
    int zeroCount1 = 0, zeroCount2 = 0;

    while (file1 >> number) {
        if (number == 0) {
            zeroCount1++;
        }
    }

    while (file2 >> number) {
        if (number == 0) {
            zeroCount2++;
        }
    }

    file1.close();
    file2.close();

    cout << "Количество нулевых элементов в a1.txt: " << zeroCount1 << endl;
    cout << "Количество нулевых элементов в a2.txt: " << zeroCount2 << endl;

    return 0;
}
