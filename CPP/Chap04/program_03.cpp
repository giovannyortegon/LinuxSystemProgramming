#include"user.h"
#include<memory>

int main() {
    std::cout <<"Start ... " <<std::endl;
        
    auto developer = std::make_unique<User>();
    developer->cheers();

    User * developer2 = new User();

    std::cout <<"developer size = " <<sizeof(developer) <<std::endl;
    std::cout <<"developer size = " <<sizeof(developer2) <<std::endl;

    delete developer2;

    std::cout <<"End ... " <<std::endl;

    return (0);
}