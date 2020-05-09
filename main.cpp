#include"header.h"

int main()
{
    Studentas a;
    srand(time(NULL));
    int kriterijus, temp_ndkiekis,irasukiekis;
    std::vector<Studentas> studentai, liudeseliai, neliudeseliai;
    std::cout<<"Iveskite 0 jei norite daryti skaiciavimus su vidurkiu arba 1 jei norite daryti skaiciavimus su mediana"<<std::endl;
    std::cin>>kriterijus;
    if(kriterijus!=0 && kriterijus!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
    std::cout<<"Iveskite norima irasu skaiciu failo generavimui:"<<std::endl;
    std::cin>>irasukiekis;
    std::cout<<"Iveskite norima namu darbu kieki:"<<std::endl;
    std::cin>>temp_ndkiekis;

    sukurimas(temp_ndkiekis, irasukiekis);
    skaitymas(studentai);
    skaiciavimai2(studentai);
   skirstymas(studentai,liudeseliai,neliudeseliai,kriterijus);
Spausdinimas(studentai,liudeseliai,neliudeseliai,kriterijus);




    return 0;
}

