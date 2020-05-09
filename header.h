#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include<fstream>
#include<chrono>
#include <stdlib.h>
#include<string>
#include<sstream>
#include<deque>
#include<iterator>

using namespace std::chrono;
class Zmogus{
protected:
    std::string vardas;
    std::string pavarde;
public:
    virtual void setvardas(std::string) = 0;
    virtual void setpavarde(std::string) = 0;

};
class Studentas: public Zmogus {
public:
    Studentas();

    ~Studentas();
    Studentas(const Studentas&);
    void setvardas(std::string);
    void setpavarde(std::string);
    void setnd(std::vector<double>);
    void setegzaminas(double);

    std::string getvardas() const;
    std::string getpavarde() const;
    double getGalutinisvid() const;
    double getGalutinismed() const;
    void skaiciavimai();
    Studentas& operator=(const Studentas& s);
    bool operator<(const Studentas& s2);
    bool operator>(const Studentas& s2);
private:

 double egzaminas;
 std::vector<double> nd;
 double vidurkis=0;
 double mediana;
 double galutinismed;
 double galutinisvid;
};
void sukurimas(int temp_ndkiekis, int irasukiekis);
void skaitymas(std::vector<Studentas>& studentai);
bool rikiavimas(Studentas s1, Studentas s2);
void skirstymas(std::vector <Studentas>& studentai, std::vector <Studentas>& liudeseliai, std::vector <Studentas>& neliudeseliai, int kriterijus);
void Spausdinimas(std::vector <Studentas>& studentai, std::vector<Studentas> liudeseliai, std::vector<Studentas> neliudeseliai, int kriterijus);
bool skolavid(Studentas& studentai);
bool skolamed(Studentas& studentai);
void skaiciavimai2(std::vector<Studentas>& studentai);


#endif // HEADER_H_INCLUDED
