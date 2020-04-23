#include "header.h"
#include <algorithm>

Studentas::Studentas()
{

}
Studentas::~Studentas()
{

}
void Studentas::setVardas(std::string v)
{
    vardas = v;
}
void Studentas::setPavarde(std::string p)
{
    pavarde = p;
}
void Studentas::setNd(int x)
{
    nd.push_back(x);
}
void Studentas::isvalyt_nd()
{
    nd.clear();
}
void Studentas::setEgzaminas(double egz)
{
    egzaminas = egz;
}
std::string Studentas::getVardas()
{
    return vardas;
}
std::string Studentas::getPavarde()
{
    return pavarde;
}
std::vector<int> Studentas::getNd()
{
    return nd;
}
int Studentas::getNdSize()
{
    return nd.size();
}
double Studentas::getEgz()
{
    return egzaminas;
}
void sukurimas(int n, int q)
{
    int  namudarb, regz;
    std::vector<int> namudarbai;
    std::ofstream irasymas;
    irasymas.open ("studentai.txt");
     for(int i=1; i<=q; i++)
    {
        irasymas<<"vardas"<<i<<" "<<"pavarde"<<i;

        for(int j=0; j<n; j++)
        {
            namudarb = rand() % 10 + 1;
            irasymas<<" "<<namudarb;
        }
        regz = rand() % 10 + 1;
        irasymas<<" "<<regz<<std::endl;
    }
irasymas.close();
}
void Studentas::skaitymas(int x, std::vector<int>& nd, std::vector<Studentas>& studentai, int n, int q)
{
    Studentas duomenys;
    std::string v,p;
    int  egz;
 auto start = high_resolution_clock::now();
std::ifstream failas("studentai.txt");
for(int i=0; i<q; i++)
    {
        duomenys.isvalyt_nd();
        failas>>v;
        failas>>p;
        duomenys.setVardas(v);
        duomenys.setPavarde(p);
           for(int j=0; j<n; j++)
           {

               failas>>x;
            duomenys.setNd(x);

           }
        failas>>egz;

        duomenys.setEgzaminas(egz);
        studentai.push_back(duomenys);



    }

auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;
std::cout<<"failo is "<<q<<" irasu nuskaitymo laikas:"<<diff.count()<<std::endl;
}
double Studentas::mediana()  {
 typedef std::vector<int>::size_type vecSize;
 vecSize size = getNdSize();
 if (getNdSize() == 0)
throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
 sort(nd.begin(), nd.end());
 vecSize vid = size / 2;
 return size % 2 == 0 ? (nd[vid] + nd[vid-1]) / 2 : nd[vid];
}
double Studentas::vidurkis()  {
 if (getNdSize() == 0)
 throw std::domain_error("negalima skaiciuoti vidurkio tusciam vektoriui");

 std::cout<<getNdSize();
 return std::accumulate(nd.begin(), nd.end(), 0.0) / getNdSize();
}
double Studentas::galbalas(int kriterijus)
{

    if(kriterijus == 0)
    {
        return 0.6 * egzaminas + 0.4 * vidurkis();
    }

    else
    {
        return 0.6 * egzaminas + 0.4 * mediana();
    }

}
bool Studentas::gavoskola(const Studentas& a, int kriterijus)
{
    return galbalas(kriterijus) < 5.0;
}
std::vector<Studentas> skirstykStudentus(std::vector<Studentas>& studentai, int kriterijus)
{
    Studentas a;
    std::vector<Studentas> liudeseliai, neliudeseliai;
    for (std::vector<Studentas>::size_type i = 0; i != studentai.size(); ++i)
    {
        if (a.gavoskola(studentai[i], kriterijus))
        {

            liudeseliai.push_back(studentai[i]);
            studentai.erase(studentai.begin() + i);
        }
    }
    return liudeseliai;
}
