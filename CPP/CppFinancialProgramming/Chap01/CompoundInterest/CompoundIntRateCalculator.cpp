/*
 * CompoundIntRateCalculator.cpp
 */
#include "CompoundIntRateCalculator.h"

CompoundIntRateCalculator::CompoundIntRateCalculator(double rate):m_rate(rate){}
CompoundIntRateCalculator::~CompoundIntRateCalculator(){}
CompoundIntRateCalculator::CompoundIntRateCalculator(const CompoundIntRateCalculator &v)
: m_rate(v.m_rate) {}
CompoundIntRateCalculator &CompoundIntRateCalculator::operator=(const CompoundIntRateCalculator &v){
    if (this != &v) {
        this->m_rate = v.m_rate;
    }
    return (*this);
}
double CompoundIntRateCalculator::multiplePeriod(double value, int numPeriods) {
    double f = value * pow((1 + m_rate), numPeriods);
    return (f);
}

double CompoundIntRateCalculator::continuousCompounding(double value, int numPeriods) {
    double f = value * exp(m_rate * numPeriods);
    return (f);
}
