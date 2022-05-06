#include"user.h"
#include<memory>


int main() {
    std::cout <<"Start ... " <<std::endl;

    auto shared1 = std::make_shared<User> ();
    {
        auto shared2 = shared1;
        User * newAllocation = new User();
        auto uniqueAllocation = std::make_unique<User>();

        std::cout << "shared2 size = " <<sizeof(shared2) <<std::endl;
        std::cout << "newAllocation size = " <<sizeof(newAllocation) <<std::endl;
        std::cout << "uniqueAllocation size = " <<sizeof(uniqueAllocation) <<std::endl;

        delete newAllocation;

        // std::cout <<" from shared1" <<std::endl;
    } 

    std::cout <<"End ... " <<std::endl;

    return (0);
}