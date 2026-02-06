#include "Racheta.h"
#include "Asteroizi.h"
#include "Piata.h"
#include "Misiuni.h"

int main(int argc, char* argv[])
{
    std::vector<Racheta> rachete;
    Racheta racheta;
    racheta.citireDateRacheta(argv[1], rachete);

    std::vector<Asteroizi> asteroizi;
    Asteroizi asteroid;
    asteroid.citireDateAsteroizi(argv[2], asteroizi);

    std::vector<Piata> piata;
    Piata piata1;
    piata1.citireDatePiata(argv[3], piata);

    std::vector<Misiuni> misiuni;
    Misiuni misiuni1;
    misiuni1.creareMisiuni(rachete, asteroizi, piata, misiuni);

    return 0;
}