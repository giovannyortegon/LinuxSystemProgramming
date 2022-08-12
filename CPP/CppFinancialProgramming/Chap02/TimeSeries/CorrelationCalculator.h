/*
 * CorrelationCalculator.h
 */
#ifndef __FinancialSample__CorrelationCalculator__
#define __FinancialSample__CorrelationCalculator__

class TimeSeries;

class CorrelationCalculator {
    public:
        CorrelationCalculator(TimeSeries &a, TimeSeries &b);
        ~CorrelationCalculator();
        CorrelationCalculator(const CorrelationCalculator &);
        CorrelationCalculator &operator = (const CorrelationCalculator &);

        double correlation();

    private:
        TimeSeries &m_tsA;
        TimeSeries &m_tsB;
};

#endif /* defined(__FinancialSample__CorrelationCalculator__) */