Создать бинарный файл, компонентами которого является структура, содержащая следующие поля: − фамилия и инициалы студентов; − номер группы; − успеваемость (массив из трех дисциплин); − размер стипендии. 
Переписать бинарный файл так, чтобы для студентов, у которых нет троек, размер стипендии должен быть увеличен на 30%.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int numberGroup;
    int grades[3];
    double scholarship;
};

int main() {

    setlocale(LC_ALL, "RU");
    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    Student students[] = {
        {"Иванов А.И.", 101, {4, 5, 4}, 1000.0},
        {"Петров Б.С.", 102, {5, 4, 3}, 1200.0},
        {"Сидоров В.В.", 103, {4, 3, 4}, 1100.0}
    };
    outFile.write(reinterpret_cast<const char*>(&students), sizeof(students));
    outFile.close();

    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return 1;
    }
    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        bool hasLowGrades = false;
        for (int i = 0; i < 3; i++) {
            if (temp.grades[i] < 4) {
                hasLowGrades = true;
                break;
            }
        }
        if (!hasLowGrades) {
            temp.scholarship *= 1.3;
        }
        cout << "Студент: " << temp.name << ", Новая стипендия: " << temp.scholarship << endl;
    }

    inFile.close();

    return 0;
}
