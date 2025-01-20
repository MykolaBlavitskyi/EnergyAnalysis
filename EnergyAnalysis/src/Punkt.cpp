#include "Punkt.h"

Punkt::Punkt(const std::string& data, double autokonsumpcja, double eksport, 
             double import, double pobor, double produkcja)
    : data(data), autokonsumpcja(autokonsumpcja), eksport(eksport),
      import(import), pobor(pobor), produkcja(produkcja) {}

std::string Punkt::getData() const {
    return data;
}

double Punkt::getAutokonsumpcja() const {
    return autokonsumpcja;
}

double Punkt::getEksport() const {
    return eksport;
}

double Punkt::getImport() const {
    return import;
}

double Punkt::getPobor() const {
    return pobor;
}

double Punkt::getProdukcja() const {
    return produkcja;
}
