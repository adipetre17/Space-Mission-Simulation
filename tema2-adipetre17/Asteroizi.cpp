#include "Asteroizi.h"

Asteroizi::Asteroizi()
    : m_idAsteroid(""),
      m_resursa(""),
      m_cantitateTotala(0), 
      m_randamentExtractie(0), 
      m_distanta(0) 
{}

Asteroizi::Asteroizi(const std::string& idAsteroid, const std::string& resursa, int cantitateTotala, int randamentExtractie, int distanta)
{
    this->m_idAsteroid = idAsteroid;
    this->m_resursa = resursa;
    this->m_cantitateTotala = cantitateTotala;
    this->m_randamentExtractie = randamentExtractie;
    this->m_distanta = distanta;
}

const std::string Asteroizi::getIdAsteroid() const
{
    return this->m_idAsteroid;
}

const std::string Asteroizi::getResursa() const
{
    return this->m_resursa;
}

const int Asteroizi::getCantitateTotala() const
{
    return this->m_cantitateTotala;
}

const int Asteroizi::getRandamentExtractie() const
{
    return this->m_randamentExtractie;
}

const int Asteroizi::getDistanta() const
{
    return this->m_distanta;
}

void Asteroizi::setResursa(const std::string& resursa)
{
    this->m_resursa =  resursa;
}

void Asteroizi::setCantitateTotala(int cantitateTotala)
{
    this->m_cantitateTotala = cantitateTotala;
}

void Asteroizi::setRandamentExtractie(int randamentExtractie)
{
    this->m_randamentExtractie = randamentExtractie;
}

void Asteroizi::setDistanta(int distanta)
{
    this->m_distanta = distanta;
}

void Asteroizi::citireDateAsteroizi(const char* numeFisier, std::vector<Asteroizi>& asteroizi)
{
    std::ifstream fisier(numeFisier);

    if(!fisier)
    {
        return;
    }

    std::string linie;

    std::getline(fisier, linie);

    while (std::getline(fisier, linie))
    {
        std::istringstream separator(linie);
        std::string idAsteroid, resursa;
        int cantitateTotala = 0;
        int randamentExtractie = 0;
        int distanta = 0;

        std::getline(separator, idAsteroid, ';');
        std::getline(separator, resursa, ';');

        std::string aux;

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            cantitateTotala = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            randamentExtractie = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            distanta = std::stoi(aux);
        }

        asteroizi.push_back(Asteroizi(idAsteroid, resursa, cantitateTotala, randamentExtractie, distanta));
    }
}
