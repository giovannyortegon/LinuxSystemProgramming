#include"BoundCalculator.h"

BoundCalculator::BoundCalculator(const std::string institution, int numPeriods, double principal,
                                double couponValue)
: m_institution(institution),
  m_numPeriods(numPeriods),
  m_principal(principal),
  m_coupon(couponValue) {}

BoundCalculator::BoundCalculator(const BoundCalculator &v)
: m_institution(v.m_institution),
  m_numPeriods(v.m_numPeriods),
  m_principal(v.m_principal),
  m_coupon(v.m_coupon) {}

BoundCalculator::~BoundCalculator() {}

BoundCalculator &BoundCalculator::operator=(const BoundCalculator &v) {
    if (this != &v) {
        this->m_institution = v.m_institution;
        this->m_principal = v.m_principal;
        this->m_numPeriods = v.m_numPeriods;
        this->m_coupon = v.m_coupon;
    }

    return (* this);
}

double BoundCalculator::interestRate() {
    return m_coupon / m_principal;
}