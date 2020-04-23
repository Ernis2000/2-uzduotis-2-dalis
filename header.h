#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<string>
#include<iomanip>
#include<random>
#include<vector>
#include<algorithm>
#include<fstream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<chrono>
#include<ctime>
#include<deque>
using namespace std::chrono;
class Studentas {
    private:
 std::string vardas;
 std::string pavarde;
 double egzaminas;
 std::vector<int> nd;


    public:

        Studentas();

        ~Studentas();

        void setVardas(std::string);
        void setPavarde(std::string);
        void setNd(int);
        void setEgzaminas(double);
        void isvalyt_nd();
        std::string getVardas();
        std::string getPavarde();
        std::vector<int> getNd();
        int getNdSize();
        double getEgz();
        double galbalas(int);
        void skaitymas(int, std::vector<int>&, std::vector<Studentas>&, int, int);
        bool gavoskola(const Studentas&, int);
        double mediana();
        double vidurkis();
};
void sukurimas(int n, int q);



std::vector<Studentas> skirstykStudentus(std::vector<Studentas>& studentai, int kriterijus);

#endif // HEADER_H_INCLUDED
