#ifndef DRZEWO_H
#define DRZEWO_H

#include <string>
#include <map>
#include <vector>
#include "Punkt.h"

class Drzewo {
public:
    // Оголошення функції розбиття дати
    void rozbijDate(const std::string& data, int& rok, int& miesiac, int& dzien, int& cwartka);

    // Інші методи
    void dodajPunkt(const Punkt& punkt);
    double sumaAutokonsumpcji(int rok, int miesiac, int dzien, int cwartka);
    double sumaEksportu(int rok, int miesiac, int dzien, int cwartka);

private:
    std::map<int, std::map<int, std::map<int, std::map<int, std::vector<Punkt>>>>> dane;
};

#endif
