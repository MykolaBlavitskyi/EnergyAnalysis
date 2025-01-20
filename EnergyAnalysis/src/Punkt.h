#ifndef PUNKT_H
#define PUNKT_H

#include <string>

class Punkt {
public:
    Punkt(const std::string& data, double autokonsumpcja, double eksport, 
          double import, double pobor, double produkcja);

    std::string getData() const;
    double getAutokonsumpcja() const;
    double getEksport() const;
    double getImport() const;
    double getPobor() const;
    double getProdukcja() const;

private:
    std::string data;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;
};

#endif
