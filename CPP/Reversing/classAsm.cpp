class ClsTest {
    int a, b;

    public:
        int add();
};

int ClsTest::add(){
    return a + b;
}

int main() {
    int z = 0;

    ClsTest x;
    z = x.add();
}