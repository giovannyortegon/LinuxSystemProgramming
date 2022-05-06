#include"user.h"

/* 
 * main automatic memory
 */
int main() {
    std::cout << "Start... " <<std::endl;
    {
        User developer;
        developer.cheers();
    }
    std::cout <<"End ... " << std::endl;

    return (0);
}