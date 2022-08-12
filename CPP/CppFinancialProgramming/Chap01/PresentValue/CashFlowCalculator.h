/*
 * CashFlowCalculator.h
 */
#ifndef __FinancialSample__CashFlowCalculator__
#define __FinancialSample__CashFlowCalculator__

#include <vector>
#include <cmath>
#include <iostream>

class CashFlowCalculator {
    public:
        CashFlowCalculator(double rate);
        CashFlowCalculator(const CashFlowCalculator &v);
        CashFlowCalculator &operator = (const CashFlowCalculator &v);
        ~CashFlowCalculator();

        void addCashPayment(double value, int timePeriod);
        double presentValue();

    private:
        std::vector<double> m_cashPayments;
        std::vector<int> m_timePeriods;
        double m_rate;
        double presentValue(double futureValue, int timePeriod);
};

#endif /* define(__FinancialSample__CashFlowCalculator__) */