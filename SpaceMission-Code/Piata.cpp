#include "Piata.h"

Piata::Piata()
    : m_resursa(""), m_pretMin(0), m_pretMax(0)
{}

Piata::Piata(const std::string& resursa, int pretMin, int pretMax)
{
    this->m_resursa = resursa;
    this->m_pretMin = pretMin;
    this->m_pretMax = pretMax;
}

const std::string Piata::getResursa() const
{
    return this->m_resursa;
}

const int Piata::getPretMin() const
{
    return this->m_pretMin;
}

const int Piata::getPretMax() const
{
    return this->m_pretMax;
}

void Piata::setResursa(const std::string& resursa)
{
    this->m_resursa = resursa;
}

void Piata::setPretMin(int pretMin)
{
    this->m_pretMin = pretMin;
}

void Piata::setPretMax(int pretMax)
{
    this->m_pretMax = pretMax;
}

void Piata::citireDatePiata(const char* numeFisier, std::vector<Piata>& piata)
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
        std::string resursa;
        int pretMin = 0;
        int pretMax = 0;

        std::getline(separator, resursa, ';');

        std::string aux;

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            pretMin = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            pretMax = std::stoi(aux);
        }

        piata.push_back(Piata(resursa, pretMin, pretMax));
    }
}
