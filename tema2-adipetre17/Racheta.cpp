#include "Racheta.h"

Racheta::Racheta()
    : m_idRacheta(""),
      m_capacitate(0),
      m_consumCombustibil(0),
      m_combustibilDisponibil(0),
      m_pretCombustibil(0.0) 
{}

Racheta::Racheta(const std::string& idRacheta, int capacitate, int consumCombustibil, int combustibilDisponibil, float pretCombustibil)
{
    this->m_idRacheta = idRacheta;
    this->m_capacitate = capacitate;
    this->m_consumCombustibil = consumCombustibil;
    this->m_combustibilDisponibil = combustibilDisponibil;
    this->m_pretCombustibil = pretCombustibil; 
}

const std::string Racheta::getIdRacheta() const
{
    return this->m_idRacheta;
}

const int Racheta::getCapacitate() const
{
    return this->m_capacitate;
}

const int Racheta::getConsumCombustibil() const 
{
    return this->m_consumCombustibil;
}

const int Racheta::getCombustibilDisponibil() const 
{
    return this->m_combustibilDisponibil;
}

const float Racheta::getPretCombustibil() const 
{
    return this->m_pretCombustibil;
}

void Racheta::setCapacitate(int capacitate) 
{
    this->m_capacitate = capacitate;
}

void Racheta::setConsumCombustibil(int consumCombustibil) 
{
    this->m_consumCombustibil = consumCombustibil;
}

void Racheta::setCombustibilDisponibil(int combustibilDisponibil) 
{
    this->m_combustibilDisponibil = combustibilDisponibil;
}

void Racheta::setPretCombustibil(int pretCombustibil) 
{
    this->m_pretCombustibil = pretCombustibil;
}

void Racheta::citireDateRacheta(const char* numeFisier, std::vector<Racheta>& rachete)
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
        std::string idRacheta;
        int capacitate = 0;
        int consumCombustibil = 0;
        int combustibilDisponibil= 0;
        float pretCombustibil = 0;

        std::getline(separator, idRacheta, ';');

        std::string aux;

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            capacitate = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            consumCombustibil = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            combustibilDisponibil = std::stoi(aux);
        }

        std::getline(separator, aux, ';');
        if (!aux.empty())
        {
            pretCombustibil = std::stof(aux);
        }

        rachete.push_back(Racheta(idRacheta, capacitate, consumCombustibil, combustibilDisponibil, pretCombustibil));
    }
}
