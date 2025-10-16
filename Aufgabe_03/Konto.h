//
// Created by Alex on 16.10.2025.
//

#ifndef AUFGABE_03_KONTO_H
#define AUFGABE_03_KONTO_H
#include <string>


class Konto {
    protected:
    std::string _name;
    double _kontostand;

    public:
    Konto(const std::string &name, double kontostand=0)
        : _name(name),
          _kontostand(kontostand) {
    }

    ~Konto() = default;

    std::string get_name() const;
    double get_kontostand() const;

    bool einzahlen(double);
    bool auszahlen(double);

    void print();

};

/*
 *If I wanted to
#include "Konto.h"
#include <gtest/gtest.h>

TEST(KontoTest, BasicOperations) {
    Konto konto("Konto", 100);

    // test einzahlen
    EXPECT_FALSE(konto.einzahlen(-100));  // negative deposit not allowed
    EXPECT_TRUE(konto.einzahlen(50));
    EXPECT_DOUBLE_EQ(konto.get_kontostand(), 150);

    // test auszahlen
    EXPECT_FALSE(konto.auszahlen(200));   // too much
    EXPECT_TRUE(konto.auszahlen(100));
    EXPECT_DOUBLE_EQ(konto.get_kontostand(), 50);
}
g++ -std=c++17 test_konto.cpp -lgtest -lgtest_main -pthread -o test_konto
./test_konto
 */


#endif //AUFGABE_03_KONTO_H