#include<cstdio>

namespace Creature {
    struct Jabberwock {
        void * tulgey_wood;
        int is_galumphing;
    };
}

namespace Func {
    void Jabberwock() {
        printf("Burbel");
    }
}

using namespace Creature;

int main() {
    Jabberwock x;
    Func::Jabberwock();
}