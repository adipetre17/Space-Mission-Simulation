Petre Adrian, 321 AB
Windows 11, IDE folosit: Visual Studio Code

Descrierea temei:

    Tema presupunea citirea datelor despre anumite rachete, asteroizi si piata de vanzare pe care sa le structuram in clase si salvarea acestor date pentru a le prelucra mai tarziu. Obiectul principal era gasirea unei combinatii potrivite si eficiente de rachete care sa adune cat mai multe resurse de pe asteroizi, avand in acelasi timp un cost cat mai mic de deplasare. Tema prezenta si anumite conditii care faceau calculul mai dificil, cum ar fi micsorarea pretului pentru o anumita resursa la un anumit prag, capacitatatea de transport a rachetei etc. Toate aceste date urmau sa fie calculate, iar mai apoi distribuite in 4 fisiere(misiuni.csv, profit_total.csv, clasament_rachete.csv, profit_resursa.csv).

Implementarea codului meu:

    Am construit 4 clase (pentru rachete, asteroizi, piata si misiuni) in care am implementat setters si getters si, in cazul primelor 3, o functie care citeste datele din fisierele de intrare si care prin apelarea constructorului specific creeaza un vector cu elementele respective (functiile de citire sunt apelate in main). 
    Majoritatea temei este rezolvata in misiuni.cpp unde am inceput prin a face o functie alegereRachetaEficienta care calculeaza scorul de eficienta al fiecarei rachete si il returneaza impreuna cu numarul de misiuni (de care voi avea nevoie mai tarziu). Apoi, am apelat functia anterioara in functia creareMisiuni si am sortat rachetele in ordinea scorului lor de eficienta, urmand sa aplic din nou acelasi algoritm ca in prima functie pentru a afla toate datele de care aveam nevoie pentru a construi vectorul ce stocheaza toate misiunile. La finalul acesteia, sunt apelate cele 4 functie de afisare (pt misiuni, clasamentul rachetelor, profitul total si profitul pe resursa).
    Aceste ultime 4 functii se folosesc de informatiile aflate pana acum si de vectorii transmisi ca parametri pentru a scrie rezultatele in fisiere specifice.

Explicarea functiei main:

    Functia main am incercat sa o pastrez cat mai simpla cu putinta, astfel in interiorul ei fiind doar apelate functiile de citire (care primesc ca parametri argv[] si vectorul specific clasei respective) si cea de creareMisiuni (functia principala a temei).

