#ifndef PIATA_H
#define PIATA_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Piata
{
    std::string m_resursa;
    int m_pretMin;
    int m_pretMax;

public:
    Piata();
    Piata(const std::string& resursa, int pretMin, int pretMax);

    const std::string getResursa() const;
    const int getPretMin() const;
    const int getPretMax() const;

    void setResursa(const std::string& resursa);
    void setPretMin(int pretMin);
    void setPretMax(int pretMax);

    void citireDatePiata(const char* numeFisier, std::vector<Piata>& piata);
};

#endif