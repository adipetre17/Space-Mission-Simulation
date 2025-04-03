#ifndef RACHETA_H
#define RACHETA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class Racheta
{
    std::string m_idRacheta;
    int m_capacitate;
    int m_consumCombustibil;
    int m_combustibilDisponibil;
    float m_pretCombustibil;

public:
    Racheta();
    Racheta(const std::string& idRacheta, int capacitate, int consumCombustibil, int combustibilDisponibil, float pretCombustibil);

    const std::string getIdRacheta() const;
    const int getCapacitate() const;
    const int getConsumCombustibil() const;
    const int getCombustibilDisponibil() const;
    const float getPretCombustibil() const;

    void setCapacitate(int capacitate);
    void setConsumCombustibil(int consumCombustibil);
    void setCombustibilDisponibil(int combustibilDisponibil);
    void setPretCombustibil(int pretCombustibil);

    void citireDateRacheta(const char* numeFisier, std::vector<Racheta>& rachete);
};

#endif