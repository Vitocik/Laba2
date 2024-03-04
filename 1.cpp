Дан файл вещественных чисел a.txt. Найти количество нулевых элементов и
сумму отрицательных элементов.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	ifstream file("a.txt");
	if (!file.is_open()) {
		cerr << "Невозможно открыть файл a.txt" << endl;
		return 1;
	}

	double number;
	int zeroCount = 0;
	double sumNeg = 0;

	while (file >> number) {
		if (number == 0) {
			zeroCount++;
		}
		else if (number < 0) {
			sumNeg += number;
		}
	}

	cout << "Количество нулевых элементов: " << zeroCount << endl;
	cout << "Сумма отрицательных элементов: " << sumNeg << endl;

	file.close();
	return 0;
}
