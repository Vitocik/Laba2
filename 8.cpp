Создать бинарный файл, компонентами которого является структура, содержащая следующие поля: − наименование товара; − стоимость товара; − единица измерения. Определить самый дорогой товар на складе и сведения о нем.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    string unit;
};

int main() {
    setlocale(LC_ALL, "RU");
    ofstream file("products.bin", ios::binary);

    if (!file.is_open()) {
        cout << "Error opening file.";
        return 1;
    }

    Product products[] = {
        {"Яблоко", 10.5, "кг"},
        {"Линейка", 50, "cм"},
        {"Шапка", 250, "шт"},
        {"Спички", 5, "шт"}
    };

    for (const Product& product : products) {
        file.write((char*)&product, sizeof(Product));
    }

    file.close();

    ifstream readfile("products.bin", ios::binary);

    if (!readfile.is_open()) {
        cout << "Error opening file.";
        return 1;
    }

    Product maxProduct;
    double maxPrice = 0.0;

    while (!readfile.eof()) {
        Product product;
        readfile.read((char*)&product, sizeof(Product));

        if (product.price > maxPrice) {
            maxPrice = product.price;
            maxProduct = product;
        }
    }

    readfile.close();

    cout << "Самый дорогой товар: " << maxProduct.name << endl;
    cout << "Цена: " << maxProduct.price << "\nЕдиница измерения: " << maxProduct.unit << endl;

    return 0;
}
