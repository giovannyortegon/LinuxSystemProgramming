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
// main automatic memory
/*int main() {
    std::cout << "Start... " <<std::endl;
    {
        User developer;
        developer.cheers();
    }
    std::cout <<"End ..." << std::endl;
}*/

// main dynamic memory
int main() {
    std::cout <<"Start... " <<std::endl;
    {
        User * developer = new User();
        developer->cheers();
        delete developer;
    }
    std::cout <<"End... " <<std::endl;
}