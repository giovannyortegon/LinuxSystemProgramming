/*
 * main.cpp
 */
#include"CorrelationCalculator.h"
#include"TimeSeries.h"

#include<iostream>

int main() {
    double price;

    TimeSeries tsa;
    TimeSeries tsb;

    for (;;) {
        std::cin >> price;
        if (price == -1) {
            break;
        }

        tsa.addValue(price);
        std::cin >> price;
        tsb.addValue(price);
    }

    CorrelationCalculator cCalc(tsa, tsb);

    auto correlation = cCalc.correlation();

    std::cout <<"correlation is " <<correlation <<std::endl;

    return (0);
}