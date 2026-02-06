#include "Misiuni.h"

Misiuni::Misiuni()
    : m_idRacheta(""),
      m_idAsteroid(""),
      m_resursa(""),
      m_cantitateExtrasa(0),
      m_combustibilConsumat(0),
      m_costCombustibil(0.0),
      m_profitBrut(0),
      m_profitNet(0.0)
{}

Misiuni::Misiuni(const std::string& idRacheta, const std::string& idAsteroid, const std::string& resursa, float cantitateExtrasa, int combustibilConsumat, float costCombustibil, int profitBrut, float profitNet)
{
    this->m_idRacheta = idRacheta;
    this->m_idAsteroid = idAsteroid;
    this->m_resursa = resursa;
    this->m_cantitateExtrasa = cantitateExtrasa;
    this->m_combustibilConsumat = combustibilConsumat;
    this->m_costCombustibil = costCombustibil;
    this->m_profitBrut = profitBrut;
    this->m_profitNet = profitNet;
}

const std::string Misiuni::getIdRacheta() const
{
    return this->m_idRacheta;
}

const std::string Misiuni::getIdAsteroid() const
{
    return this->m_idAsteroid;
}

const std::string Misiuni::getResursa() const
{
    return this->m_resursa;
}

const float Misiuni::getCantitateExtrasa() const
{
    return this->m_cantitateExtrasa;
}

const int Misiuni::getCombustibilConsumat() const
{
    return this->m_combustibilConsumat;
}

const float Misiuni::getCostCombustibil() const
{
    return this->m_costCombustibil;
}

const int Misiuni::getProfitBrut() const
{
    return this->m_profitBrut;
}

const float Misiuni::getProfitNet() const
{
    return this->m_profitNet;
}

void Misiuni::setResursa(const std::string& resursa)
{
    this->m_resursa = resursa;
}

void Misiuni::setCantitateExtrasa(int cantitateExtrasa)
{
    this->m_cantitateExtrasa = cantitateExtrasa;
}

void Misiuni::setCombustibilConsumat(int combustibilConsumat)
{
    this->m_combustibilConsumat = combustibilConsumat;
}

void Misiuni::setCostCombustibil(int costCombustibil)
{
    this->m_costCombustibil = costCombustibil;
}

void Misiuni::setProfitBrut(int profitBrut)
{
    this->m_profitBrut = profitBrut;
}

void Misiuni::setProfitNet(int profitNet)
{
    this->m_profitNet = profitNet;
}

std::pair<float, int> Misiuni::alegereRachetaEficienta(const Racheta& racheta, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata)
{
    float profitNetTotal = 0.0;
    int nrMisiuni = 0;
    // se vor face calcule pentru a vedea care e cea mai eficienta racheta dpdv al raportului profitNet / nrMisiuni
    for (const auto& asteroid : asteroizi)
    {
        float pretActual = 0.0;
        for (const auto& p : piata)
        {
            if (p.getResursa() == asteroid.getResursa())
            {
                pretActual = p.getPretMax();
            }
        }
        float cantitateRamasa = asteroid.getCantitateTotala();
        float cantitateExtrasaGlobala = 0.0;

        while (cantitateRamasa > 0 && racheta.getCombustibilDisponibil() > 0)
        {
            float capacitateDisponibila = std::min((float)racheta.getCapacitate(), cantitateRamasa);
            int consumCombustibil = ((asteroid.getDistanta() * 2 * racheta.getConsumCombustibil()) / 1000);

            if (racheta.getCombustibilDisponibil() < consumCombustibil)
            {
                break;
            }

            float cantitateExtrasa = (capacitateDisponibila * asteroid.getRandamentExtractie()) / 100;

            if (cantitateExtrasa + cantitateExtrasaGlobala > 10000.0)
            {
                float cantitateSuplimentara = cantitateExtrasa + cantitateExtrasaGlobala - 10000.0;
                float cantitateLaPretVechi = cantitateExtrasa - cantitateSuplimentara;

                float profitBrutPartea1 = cantitateLaPretVechi * pretActual;
                for (const auto& p : piata)
                {
                    if (p.getResursa() == asteroid.getResursa())
                    {
                        pretActual = std::max(pretActual * 0.9f, (float)p.getPretMin());
                        break;
                    }
                }

                float profitBrutPartea2 = cantitateSuplimentara * pretActual;
                float profitBrut = profitBrutPartea1 + profitBrutPartea2;

                float costCombustibil = consumCombustibil * racheta.getPretCombustibil();
                profitNetTotal += profitBrut - costCombustibil;

                cantitateExtrasaGlobala = cantitateSuplimentara;
            }
            else
            {
                cantitateExtrasaGlobala += cantitateExtrasa;

                float profitBrut = cantitateExtrasa * pretActual;
                float costCombustibil = consumCombustibil * racheta.getPretCombustibil();
                profitNetTotal += profitBrut - costCombustibil;
            }

            cantitateRamasa -= capacitateDisponibila;
            nrMisiuni++;

            while (cantitateExtrasaGlobala >= 10000.0)
            {
                for (const auto& p : piata)
                {
                    if (p.getResursa() == asteroid.getResursa())
                    {
                        pretActual = std::max(pretActual * 0.9f, (float)p.getPretMin());
                        cantitateExtrasaGlobala -= 10000.0;
                        break;
                    }
                }
            }
        }
    }

    if (nrMisiuni == 0)
    {
        return {0.0f, 0};
    }

    float profitPeMisiune = profitNetTotal / nrMisiuni;
    return {profitPeMisiune, nrMisiuni};
}

void Misiuni::creareMisiuni(std::vector<Racheta> rachete, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata, std::vector<Misiuni>& misiuni)
{
    std::vector<Racheta> racheteSortate = rachete;
    std::map<std::string, std::pair<float, int>> eficientaRachete;

    for (const auto& racheta : racheteSortate)
    {
        eficientaRachete[racheta.getIdRacheta()] = alegereRachetaEficienta(racheta, asteroizi, piata);
    }
    //sorteaza rachetele dupa eficienta
    std::sort(racheteSortate.begin(), racheteSortate.end(), [&](const Racheta& a, const Racheta& b)
    {
        return eficientaRachete[a.getIdRacheta()].first > eficientaRachete[b.getIdRacheta()].first;
    });
    //acelasi algortim ca mai sus, dar de data asta avem nevoie de el la construirea misiunilor
    for (auto& asteroid : asteroizi)
    {
        float cantitateRamasa = asteroid.getCantitateTotala();
        float pretActual = 0.0;

        for (const auto& p : piata)
        {
            if (p.getResursa() == asteroid.getResursa())
            {
                pretActual = p.getPretMax();
            }
        }

        float cantitateExtrasaGlobala = 0.0;

        for (auto& racheta : racheteSortate)
        {
            while (cantitateRamasa > 0 && racheta.getCombustibilDisponibil() > 0)
            {
                float capacitateDisponibila = std::min((float)racheta.getCapacitate(), cantitateRamasa);

                int consumCombustibil = ((asteroid.getDistanta() * 2 * racheta.getConsumCombustibil()) / 1000);
                if (racheta.getCombustibilDisponibil() < consumCombustibil)
                {
                    break;
                }

                float cantitateExtrasa = (capacitateDisponibila * asteroid.getRandamentExtractie()) / 100;

                if (cantitateExtrasa + cantitateExtrasaGlobala > 10000.0)
                {
                    float cantitateSuplimentara = cantitateExtrasa + cantitateExtrasaGlobala - 10000.0;
                    float cantitateLaPretVechi = cantitateExtrasa - cantitateSuplimentara;

                    float profitBrutPartea1 = cantitateLaPretVechi * pretActual;

                    for (const auto& p : piata)
                    {
                        if (p.getResursa() == asteroid.getResursa())
                        {
                            pretActual = std::max(pretActual * 0.9f, (float)p.getPretMin());
                            break;
                        }
                    }

                    float profitBrutPartea2 = cantitateSuplimentara * pretActual;
                    float profitBrut = profitBrutPartea1 + profitBrutPartea2;

                    float costCombustibil = consumCombustibil * racheta.getPretCombustibil();
                    float profitNet = profitBrut - costCombustibil;

                    Misiuni misiune(racheta.getIdRacheta(), asteroid.getIdAsteroid(), asteroid.getResursa(),
                                    cantitateExtrasa, consumCombustibil, costCombustibil, profitBrut, profitNet);
                    misiuni.push_back(misiune);

                    cantitateExtrasaGlobala = cantitateSuplimentara;
                }
                else
                {
                    cantitateExtrasaGlobala += cantitateExtrasa;

                    float profitBrut = cantitateExtrasa * pretActual;
                    float costCombustibil = consumCombustibil * racheta.getPretCombustibil();
                    float profitNet = profitBrut - costCombustibil;

                    Misiuni misiune(racheta.getIdRacheta(), asteroid.getIdAsteroid(), asteroid.getResursa(),
                                    cantitateExtrasa, consumCombustibil, costCombustibil, profitBrut, profitNet);
                    misiuni.push_back(misiune);
                }

                cantitateRamasa -= capacitateDisponibila;
                racheta.setCombustibilDisponibil(racheta.getCombustibilDisponibil() - consumCombustibil);

                while (cantitateExtrasaGlobala >= 10000.0)
                {
                    for (const auto& p : piata)
                    {
                        if (p.getResursa() == asteroid.getResursa())
                        {
                            pretActual = std::max(pretActual * 0.9f, (float)p.getPretMin());
                            cantitateExtrasaGlobala -= 10000.0;
                            break;
                        }
                    }
                }
            }

            if (cantitateRamasa <= 0)
            {
                break;
            }
        }
    }

    afisareMisiuni("misiuni.csv", misiuni);
    afisareProfitTotal("profit_total.csv", misiuni, racheteSortate, rachete);
    afisareProfitResursa("profit_resursa.csv", misiuni);
    afisareClasamentRachete("clasament_rachete.csv", rachete, asteroizi, piata, misiuni);
} 

void Misiuni::afisareMisiuni(const char* fisier, std::vector<Misiuni> misiuni)
{
    std::ofstream fisier_out("misiuni.csv");
    fisier_out<<"ID Rachetă;ID Asteroid;Resursă;Cantitate extrasă (kg);Combustibil consumat (kg);Cost combustibil ($);Profit brut ($);Profit net ($)\n";
    for (auto& misiune : misiuni)
    {
        fisier_out << misiune.getIdRacheta() << ";"
                   << misiune.getIdAsteroid() << ";"
                   << misiune.getResursa() << ";"
                   << misiune.getCantitateExtrasa() << ";"
                   << misiune.getCombustibilConsumat() << ";"
                   << misiune.getCostCombustibil() << ";"
                   << misiune.getProfitBrut() << ";"
                   << misiune.getProfitNet() << "\n";
    }

    fisier_out.close();
}

void Misiuni::afisareProfitTotal(const char* fisier, std::vector<Misiuni> misiuni, std::vector<Racheta> racheteSortate, std::vector<Racheta> rachete)
{
    std::ofstream fisier_out("profit_total.csv");
    fisier_out<<"ID Rachetă;Profit brut ($);Cost total combustibil ($);Profit net ($)\n";
    std::string id = racheteSortate.front().getIdRacheta();
    for (const auto& r : rachete)
    {
        if (r.getIdRacheta() == id)
        {
            int profitBrut = 0;
            float costTotal = 0.0;
            float profitNet = 0.0;
            for (const auto& m : misiuni)
            {
                profitBrut += m.getProfitBrut();
                costTotal += m.getCostCombustibil();
                profitNet += m.getProfitNet();
            }
            fisier_out << r.getIdRacheta() << ";"
                       << profitBrut << ";"
                       << costTotal << ";"
                       << profitNet << "\n";
        }
        else
        {
            fisier_out << r.getIdRacheta() << ";" << "0;" << "0;" << "0\n";
        }
    }
    fisier_out.close();
}

void Misiuni::afisareProfitResursa(const char* fisier, std::vector<Misiuni> misiuni)
{
    std::ofstream fisier_out("profit_resursa.csv");
    fisier_out << "Resursă;Cantitate extrasă (kg);Profit brut ($)\n";
    std::map <std::string, std::pair<float, int>> profitPeResursa;

    for (const auto& m : misiuni)
    {
        std::string resursa = m.getResursa();
        int profitBrut = m.getProfitBrut();
        float cantitateExtrasa = m.getCantitateExtrasa();

        profitPeResursa[resursa].first += cantitateExtrasa;
        profitPeResursa[resursa].second += profitBrut;
    }

    for(const auto& aux : profitPeResursa)
    {
        fisier_out << aux.first << ";"
                   << aux.second.first << ";"
                   << aux.second.second << "\n";
    }
    fisier_out.close();
}

void Misiuni::afisareClasamentRachete (const char* fisier, std::vector<Racheta> rachete, std::vector<Asteroizi> asteroizi, std::vector<Piata> piata, std::vector<Misiuni> misiuni)
{
    std::ofstream fisier_out("clasament_rachete.csv");
    fisier_out << "Loc;ID Rachetă;Profit net ($);Număr misiuni;Scor eficiență\n";

    std::vector<Racheta> racheteSortate = rachete;
    std::map<std::string, std::pair<float, int>> eficientaRachete;
    for (const auto& racheta : racheteSortate)
    {
        eficientaRachete[racheta.getIdRacheta()] = alegereRachetaEficienta(racheta, asteroizi, piata);
    }

    std::sort(racheteSortate.begin(), racheteSortate.end(), [&](const Racheta& a, const Racheta& b)
    {
        return eficientaRachete[a.getIdRacheta()].first > eficientaRachete[b.getIdRacheta()].first;
    });

    float profitNetTotal = 0.0;
    for(const auto& m : misiuni)
    {
        float profitNet = m.getProfitNet();
        profitNetTotal += profitNet; 
    }

    int loc = 1; 

    const auto& primaRacheta = racheteSortate.front();
    const auto& detalii = eficientaRachete[primaRacheta.getIdRacheta()];
    float scorEficienta = detalii.first;
    int nrMisiuni = detalii.second;

    fisier_out << loc << ";"
               << primaRacheta.getIdRacheta() << ";"
               << profitNetTotal << ";"
               << nrMisiuni << ";"
               << scorEficienta << "\n";             
    loc++;

    for (const auto& r : rachete)
    {
        if (r.getIdRacheta() == primaRacheta.getIdRacheta())
        {
            continue;
        }

        fisier_out << loc << ";"
                   << r.getIdRacheta() << ";"
                   << 0 << ";"
                   << 0 << ";"
                   << 0 << "\n"; 
        loc++;
    }
    fisier_out.close();

}
