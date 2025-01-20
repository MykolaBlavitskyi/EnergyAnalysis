#include "Drzewo.h"
#include "Punkt.h"
#include <sstream>
#include <iostream>

// Функція для перетворення рядка дати в рік, місяць, день та ćwiartку
void Drzewo::rozbijDate(const std::string& data, int& rok, int& miesiac, int& dzien, int& cwartka) {
    // Розбиваємо дату на рік, місяць, день, годину та хвилини
    std::stringstream ss(data);
    std::string rok_str, miesiac_str, dzien_str, godzina_str, minuta_str;
    char separator;

    // Формат дати: yyyy-MM-dd HH:mm
    ss >> rok_str >> separator >> miesiac_str >> separator >> dzien_str >> godzina_str >> separator >> minuta_str;

    rok = std::stoi(rok_str);
    miesiac = std::stoi(miesiac_str);
    dzien = std::stoi(dzien_str);

    int godzina = std::stoi(godzina_str);
    int minuta = std::stoi(minuta_str);

    // Визначаємо ćwiartку на основі години
    if (godzina < 6) {
        cwartka = 0;  // 00:00 - 5:45
    } else if (godzina < 12) {
        cwartka = 1;  // 6:00 - 11:45
    } else if (godzina < 18) {
        cwartka = 2;  // 12:00 - 17:45
    } else {
        cwartka = 3;  // 18:00 - 23:45
    }
}

// Метод для додавання нового пункту в дерево
void Drzewo::dodajPunkt(const Punkt& punkt) {
    int rok, miesiac, dzien, cwartka;
    rozbijDate(punkt.getData(), rok, miesiac, dzien, cwartka);

    // Додаємо дані в структуру дерева
    dane[rok][miesiac][dzien][cwartka].push_back(punkt);
}

// Функція для обчислення суми автоконсумпції для заданого часу
double Drzewo::sumaAutokonsumpcji(int rok, int miesiac, int dzien, int cwartka) {
    double suma = 0.0;

    // Перевірка наявності даних для заданого часу
    if (dane.find(rok) != dane.end()) {
        if (dane[rok].find(miesiac) != dane[rok].end()) {
            if (dane[rok][miesiac].find(dzien) != dane[rok][miesiac].end()) {
                if (dane[rok][miesiac][dzien].find(cwartka) != dane[rok][miesiac][dzien].end()) {
                    // Якщо дані є, додаємо всі значення автоконсумпції для заданої ćwiartки
                    for (const auto& punkt : dane[rok][miesiac][dzien][cwartka]) {
                        suma += punkt.getAutokonsumpcja();
                    }
                }
            }
        }
    }

    return suma;
}

// Функція для обчислення суми експортованої енергії
double Drzewo::sumaEksportu(int rok, int miesiac, int dzien, int cwartka) {
    double suma = 0.0;

    if (dane.find(rok) != dane.end() &&
        dane[rok].find(miesiac) != dane[rok].end() &&
        dane[rok][miesiac].find(dzien) != dane[rok][miesiac].end() &&
        dane[rok][miesiac][dzien].find(cwartka) != dane[rok][miesiac][dzien].end()) {
        for (const auto& punkt : dane[rok][miesiac][dzien][cwartka]) {
            suma += punkt.getEksport();
        }
    }

    return suma;
}

// Аналогічні функції для інших типів даних (import, pobor, produkcja) можна реалізувати подібно
