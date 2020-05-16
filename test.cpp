#include "pch.h"
#include "../v2.0/funkcijos.cpp"
TEST(SukurimoTest, Irasukiekis) {
    std::vector<Studentas> studentai;
    sukurimas(5, 5);
    skaitymas(studentai,5);
    ASSERT_EQ(studentai.size(), 5);
    studentai.clear();
    sukurimas(5, 10);
    skaitymas(studentai, 10);
    ASSERT_EQ(studentai.size(), 10);

}
TEST(SkaiciavimuTest, vidurkis)
{
    std::vector<double> testnd{ 10,9,8 };
    ASSERT_EQ(vidurkioskaiciavimas(testnd),9);
}
TEST(SkaiciavimuTest, mediana)
{
    std::vector<double> testnd{ 10,9,8 };
    ASSERT_EQ(vidurkioskaiciavimas(testnd), 9);
}
