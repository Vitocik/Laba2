Ввести в Memo или в StringGrid некоторое количество символов латинского алфавита и записать их в бинарный файл. 
Переписать бинарный файл так, чтобы все символы были записаны заглавными буквами.Распечатать символы до и после изменения данных в файле.

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
using std::ios;

int main() {
    setlocale(LC_ALL, "Ru");
    char latinChars[] = "abcdefghijklmnopqrstuvwxyz";
    ofstream originalFile("original.dat", ios::out | ios::binary);
    originalFile.write((char*)latinChars, sizeof(latinChars) - 1);
    originalFile.close();

    ifstream readFile("original.dat", ios::in | ios::binary);
    char readChars[sizeof(latinChars)];
    readFile.read((char*)readChars, sizeof(readChars));
    cout << "Символы до изменения в файле: " <<  readChars << endl;
    readFile.close();

    for (int i = 0; i < sizeof(readChars); ++i) {
        readChars[i] = toupper(readChars[i]);
    }

    ofstream modifiedFile("modified.dat", ios::out | ios::binary);
    modifiedFile.write((char*)readChars, sizeof(readChars) - 1);
    modifiedFile.close();

    ifstream newFile("modified.dat", ios::in | ios::binary);
    char newChars[sizeof(latinChars)];
    newFile.read((char*)newChars, sizeof(newChars));
    cout << "Символы после изменения в файле: " << newChars << endl;
    newFile.close();

    return 0;
}
