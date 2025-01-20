#include "CSVReader.h"
#include "Punkt.h"
#include <fstream>
#include <sstream>

std::vector<Punkt> wczytajDane(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    std::string linia;
    std::vector<Punkt> dane;

    std::getline(plik, linia);

    while (std::getline(plik, linia)) {
        std::stringstream ss(linia);
        std::string data;
        double autokonsumpcja, eksport, import, pobor, produkcja;

        if (ss >> data >> autokonsumpcja >> eksport >> import >> pobor >> produkcja) {
            dane.push_back(Punkt(data, autokonsumpcja, eksport, import, pobor, produkcja));
        } else {
            std::ofstream logError("log_error.txt", std::ios::app);
            logError << "Błąd wczytywania linii: " << linia << std::endl;
        }
    }
    return dane;
}
