#include"user.h"

/*
 * main dynamic memory
 */
int main() {
    std::cout <<"Start... " <<std::endl;
    {
        User * developer = new User();
        developer->cheers();
        delete developer;
    }
    std::cout <<"End... " <<std::endl;

    return (0);
}