#ifndef DRZEWO_H
#define DRZEWO_H

#include <map>
#include <vector>
#include "Punkt.h"

class Drzewo {
public:
    void dodajPunkt(const Punkt& punkt);

    double sumaAutokonsumpcji(int rok, int miesiac, int dzien, int cwartka);
    double sumaEksportu(int rok, int miesiac, int dzien, int cwartka);
    double sumaImportu(int rok, int miesiac, int dzien, int cwartka);
    double sumaPoboru(int rok, int miesiac, int dzien, int cwartka);
    double sumaProdukcji(int rok, int miesiac, int dzien, int cwartka);

private:
    std::map<int, std::map<int, std::map<int, std::map<int, std::vector<Punkt>>>>> dane;
};

#endif
