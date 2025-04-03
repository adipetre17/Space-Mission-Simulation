#ifndef MISIUNI_H
#define MISIUNI_H

#include "Racheta.h"
#include "Asteroizi.h"
#include "Piata.h"
#include <unordered_set>
#include <map>
#include <algorithm>

class Misiuni
{
    std::string m_idRacheta;
    std::string m_idAsteroid;
    std::string m_resursa;
    float m_cantitateExtrasa;
    int m_combustibilConsumat;
    float m_costCombustibil;
    int m_profitBrut;
    float m_profitNet;

public:
    Misiuni();
    Misiuni(const std::string& idRacheta, const std::string& idAsteroid, const std::string& resursa, float cantitateExtrasa, int combustibilConsumat, float costCombustibil, int profitBrut, float profitNet);

    const std::string getIdRacheta() const;
    const std::string getIdAsteroid() const;
    const std::string getResursa() const;
    const float getCantitateExtrasa() const;
    const int getCombustibilConsumat() const;
    const float getCostCombustibil() const;
    const int getProfitBrut() const;
    const float getProfitNet() const;

    void setResursa(const std::string& resursa);
    void setCantitateExtrasa(int cantitateExtrasa);
    void setCombustibilConsumat(int combustibilConsumat);
    void setCostCombustibil(int costCombustibil);
    void setProfitBrut(int profitBrut);
    void setProfitNet(int profitNet);

    std::pair<float, int> alegereRachetaEficienta(const Racheta& racheta, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata);
    void creareMisiuni(std::vector<Racheta> rachete, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata, std::vector<Misiuni>& misiuni);
    void afisareMisiuni(const char* fisier, std::vector<Misiuni> misiuni);
    void afisareProfitTotal(const char* fisier, std::vector<Misiuni> misiuni, std::vector<Racheta> racheteSortate, std::vector<Racheta> rachete);
    void afisareProfitResursa(const char* fisier, std::vector<Misiuni> misiuni);
    void afisareClasamentRachete (const char* fisier, std::vector<Racheta> rachete, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata, std::vector<Misiuni> misiuni);

};

#endif