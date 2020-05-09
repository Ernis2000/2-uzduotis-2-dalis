#include "header.h"

Studentas::Studentas()
{
    int egzaminas=0;
    double vidurkis=0.0;
    double mediana=0.0;
    double galutinisvid=0.0;
    double galutinismed=0.0;
}
Studentas::~Studentas()
{}
Studentas::Studentas(const Studentas& kazkokiaklase)
{
    vardas = kazkokiaklase.vardas;
    pavarde = kazkokiaklase.pavarde;
    nd = kazkokiaklase.nd;
    egzaminas = kazkokiaklase.egzaminas;
    vidurkis = kazkokiaklase.vidurkis;
    mediana = kazkokiaklase.mediana;
    galutinisvid = kazkokiaklase.galutinisvid;
    galutinismed = kazkokiaklase.galutinismed;
}
void Studentas::setvardas(std::string tempvardas)
{
    vardas=tempvardas;
}
void Studentas::setpavarde(std::string temppavarde)
{
    pavarde=temppavarde;
}
void Studentas::setnd(std::vector<double> tempnd)
{
    nd = tempnd;
}
void Studentas::setegzaminas(double tempegzaminas)
{
    egzaminas=tempegzaminas;
}
std::string Studentas::getvardas() const{
return vardas;
}
std::string Studentas::getpavarde() const{
return pavarde;
}
double Studentas::getGalutinismed() const{
return galutinismed;
}
double Studentas::getGalutinisvid() const{
return galutinisvid;
}
void Studentas::skaiciavimai()
{
    int pozicija=nd.size();
    sort(nd.begin(),nd.end());


        if(pozicija % 2 == 0)
        {
            mediana = ((nd.at(pozicija / 2)) + (nd.at(pozicija / 2 - 1))) / 2;
        }
        else {
			mediana = nd.at(pozicija / 2);
		}
		galutinismed = (0.4 * mediana) + (0.6 * egzaminas);

		for (int j = 0; j < nd.size(); j++) {
			vidurkis += nd.at(j);
		}

		vidurkis = vidurkis / nd.size();
		galutinisvid = (0.4 * vidurkis) + (0.6 * egzaminas);

}
void sukurimas(int temp_ndkiekis, int irasukiekis)
{
    std::ofstream failas("studentai.txt");
    failas << std::setw(20) << std::left << "Vardas" << std::setw(21) << "Pavarde";
      for(int i=1; i<=temp_ndkiekis;i++)
      {
          failas << "ND" << i<<"     ";
      }
    failas << "Egz." << std::endl;
    for(int j=1; j<=irasukiekis;j++)
    {
      failas << "Vardas" << std::setw(14) << std::left << j << "Pavarde" << std::setw(14) << std::left << j;
      for(int k=1;k<=temp_ndkiekis;k++)
      {
         int pazymys = (rand() % 10);
         failas << std::setw(10) << std::left << pazymys;
      }
      int egzaminas = (rand() % 10);
      failas << std::setw(10) << std::left << egzaminas<<std::endl;
    }


    failas.close();
}
void skaitymas(std::vector<Studentas>& studentai)
{
    std::ifstream failas("studentai.txt");
    std::string a;
    int ndkiekis = 0;
    int temp;

    Studentas Duomenys;

    std::string tempvardas,temppavarde;
    double tempegzaminas;
    std::vector<double> tempnd;
    if(!failas)
    {
        std::cout<<"Nera failo!"<<std::endl;
        exit(0);
    }
    failas>>a>>a>>a;

    while (a[0] == 'N') {
		ndkiekis++;
		failas >> a;

	}
    while(!failas.eof())
    {
        failas>>tempvardas>>temppavarde;

        Duomenys.setvardas(tempvardas);
        Duomenys.setpavarde(temppavarde);

        for(int i=0; i<ndkiekis;i++)
        {
            failas>>temp;
            tempnd.push_back(temp);
        }
        failas>>tempegzaminas;
        Duomenys.setegzaminas(tempegzaminas);
        Duomenys.setnd(tempnd);
        studentai.push_back(Duomenys);
        tempnd.clear();
    }
    failas.close();
}
void skaiciavimai2(std::vector<Studentas>& studentai)
{
    for(int i=0;i<studentai.size();i++)
    {
        studentai.at(i).skaiciavimai();
    }
}
bool rikiavimas(Studentas s1, Studentas s2)
{
    if(s1.getvardas() != s2.getvardas()) return s1.getvardas()<s2.getvardas();
    else return s1.getpavarde() < s2.getpavarde();
}
bool skolavid(Studentas& studentai)
{
    return (studentai.getGalutinisvid()>5);
}

bool skolamed(Studentas& studentai)
{
    return (studentai.getGalutinismed()>5);
}
void skirstymas(std::vector <Studentas>& studentai, std::vector <Studentas>& liudeseliai, std::vector <Studentas>& neliudeseliai, int kriterijus){

	if (kriterijus == 0) {

		std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(liudeseliai), skolavid);
		std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(neliudeseliai), skolavid);
		studentai.erase(studentai.begin(), studentai.end());

	}

	else {

		std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(liudeseliai), skolamed);

		std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(neliudeseliai), skolamed);
		studentai.erase(studentai.begin(), studentai.end());
	}

}
void Spausdinimas(std::vector <Studentas>& studentai, std::vector<Studentas> liudeseliai, std::vector<Studentas> neliudeseliai, int kriterijus) {

    std::ofstream failas2("liudeseliai.txt");

    failas2<< std::left<<std::setw(15)<<"Vardas:"<<std::left<<std::setw(20)<<"Pavarde:";
    if(kriterijus == 1)
    {
        failas2<<"Gal. med." <<std::endl;
    }
    else {
        failas2<<"Gal. vid. "<<std::endl;
    }
    for (int i = 0; i < liudeseliai.size(); i++)
    {
        failas2 << std::left << std::setw(15) << liudeseliai.at(i).getvardas() << std::left << std::setw(20) << liudeseliai.at(i).getpavarde() ;
		if (kriterijus == 0) {
			failas2 << std::left << std::setw(9) << std::setprecision(3) << liudeseliai.at(i).getGalutinisvid();
		}

		if (kriterijus == 1) {
			failas2 << std::left << std::setw(9) << std::setprecision(2) << liudeseliai.at(i).getGalutinismed();
		}

		failas2 << std::endl;
    }
    failas2.close();

    std::ofstream failas3("neliudeseliai.txt");

    failas3<< std::left<<std::setw(15)<<"Vardas:"<<std::left<<std::setw(20)<<"Pavarde:";
    if(kriterijus == 1)
    {
        failas3<<"Gal. med." <<std::endl;
    }
    else {
        failas3<<"Gal. vid. "<<std::endl;
    }
    sort(neliudeseliai.begin(),neliudeseliai.end(),rikiavimas);
    for (int i = 0; i < neliudeseliai.size(); i++)
    {
        failas3 << std::left << std::setw(15) <<neliudeseliai.at(i).getvardas() << std::left << std::setw(20) << neliudeseliai.at(i).getpavarde() ;
		if (kriterijus == 0) {
			failas3 << std::left << std::setw(9) << std::setprecision(3) << neliudeseliai.at(i).getGalutinisvid();
		}

		if (kriterijus == 1) {
			failas3 << std::left << std::setw(9) << std::setprecision(2) << neliudeseliai.at(i).getGalutinismed();
		}

		failas3 << std::endl;
}
failas3.close();
}
Studentas& Studentas::operator=(const Studentas& s) {
	if (&s == this) return *this;
	vardas = s.getvardas();
	pavarde = s.getpavarde();
	galutinismed = s.getGalutinismed();
	galutinisvid = s.getGalutinisvid();
	return *this;
}
bool Studentas::operator<(const Studentas& s2)
{
    if( vardas != s2.getvardas())
        return vardas > s2.getvardas();
    else return pavarde > s2.getpavarde();
}
bool Studentas::operator>(const Studentas& s2)
{
    if( vardas != s2.getvardas())
        return vardas > s2.getvardas();
    else return pavarde > s2.getpavarde();
}
