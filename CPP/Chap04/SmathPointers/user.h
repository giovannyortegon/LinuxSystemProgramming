#ifndef __USER__
#define __USER__

#include<iostream>

class User {
    public:
        User() {
            std::cout <<"Usage constructor" << std::endl;
        };
        ~User() {
            std::cout <<"Usage destructor" << std::endl;
        };
        void cheers() {
            std::cout <<"Hello!" << std::endl;
        };
};

#endif /* __USER__ */