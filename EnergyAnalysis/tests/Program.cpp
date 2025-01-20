#include <iostream>
#include <vector>
#include "Punkt.h"
#include "Drzewo.h"
#include "CSVReader.h"

int main() {
    std::vector<Punkt> dane = wczytajDane("dane.csv");

    Drzewo drzewo;
    for (const auto& punkt : dane) {
        drzewo.dodajPunkt(punkt);
    }

    
    std::cout << "Suma autokonsumpcji: " << drzewo.sumaAutokonsumpcji(2021, 10, 3, 2) << std::endl;

    return 0;
}