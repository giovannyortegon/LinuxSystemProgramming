/*
 * _MONITOR_H_
 */
#ifndef _MONITOR_H_
#define _MONITOR_H_

#include<iostream>

class Monitor
{
private:
    int idMonitor;
    std::string marca;
    int tamano;

public:
    Monitor();
    Monitor(std::string, int);
    ~Monitor();

    static int count;
    static int counter();

    void Print();
};

#endif /* _MONITOR_H_ */