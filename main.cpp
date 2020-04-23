#include "header.h"

int main()
{
    Studentas a;
    srand(time(NULL));
    int kriterijus, x, n, q;
    double egzaminas;
    std::vector<int> nd;
    std::vector<Studentas> studentai;
    std::cout<<"Iveskite 0 jei norite daryti skaiciavimus su vidurkiu arba 1 jei norite daryti skaiciavimus su mediana"<<std::endl;
    std::cin>>kriterijus;
    if(kriterijus!=0 && kriterijus!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
    std::cout<<"Iveskite norima irasu kieki:"<<std::endl;
    std::cin>>q;
    std::cout<<"Iveskite norima namu darbu kieki:"<<std::endl;
    std::cin>>n;
    sukurimas(n,q);
    a.skaitymas(x,nd,studentai,n,q);
    auto start = high_resolution_clock::now();
    skirstykStudentus(studentai,kriterijus);
auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;
std::cout<<" studentu suskirstymo laikas:"<<diff.count()<<std::endl;
    return 0;
}
