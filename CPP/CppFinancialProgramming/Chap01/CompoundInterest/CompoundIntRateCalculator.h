/*
 * CompoundIntRateCalculator.h
 */
#ifndef __FinancialSample__CompoundIntRateCalculator__
#define __FinancialSample__CompoundIntRateCalculator__

#include<iostream>
#include<cmath>

class CompoundIntRateCalculator {
    public:
        CompoundIntRateCalculator(double rate);
        CompoundIntRateCalculator(const CompoundIntRateCalculator &v);
        CompoundIntRateCalculator &operator = (const CompoundIntRateCalculator &v);
        ~CompoundIntRateCalculator();

        double multiplePeriod(double rate, int numPeriods);
        double continuousCompounding(double value, int numPeriods);

    private:
        double m_rate;

};

#endif /* deifined(__FinancialSample__CompoundIntRateCalculator__) */