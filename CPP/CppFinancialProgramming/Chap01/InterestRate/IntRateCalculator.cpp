#include "IntRateCalculator.h"

IntRateCalculator::IntRateCalculator(double rate) : m_rate(rate) {}
IntRateCalculator::~IntRateCalculator() {}
IntRateCalculator::IntRateCalculator(const IntRateCalculator &v) : m_rate(v.m_rate) {}
IntRateCalculator &IntRateCalculator::operator=(const IntRateCalculator &v) {
    if (&v != this) {
        this->m_rate = v.m_rate;
    }

    return (*this);
}