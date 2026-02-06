#ifndef ASTEROIZI_H
#define ASTEROIZI_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Asteroizi
{
    std::string m_idAsteroid;
    std::string m_resursa;
    int m_cantitateTotala;
    int m_randamentExtractie;
    int m_distanta;

public:
    Asteroizi();
    Asteroizi(const std::string& idAsteroid, const std::string& resursa, int cantitateTotala, int randamentExtractie, int distanta);

    const std::string getIdAsteroid() const;
    const std::string getResursa() const;
    const int getCantitateTotala() const;
    const int getRandamentExtractie() const;
    const int getDistanta() const;

    void setResursa(const std::string& resursa);
    void setCantitateTotala(int cantitateTotala);
    void setRandamentExtractie(int randamentExtractie);
    void setDistanta(int distanta);

    void citireDateAsteroizi(const char* numeFisier, std::vector<Asteroizi>& asteroizi);
};

#endif