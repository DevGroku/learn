#include <iostream>

void f() { std::cout << "f()" << std::endl; }

namespace zeta
{
    void f()
    {
        std::cout << "zeta::f()" << std::endl;
    }
}


void test1()
{
    std::cout << "############ test1" << std::endl;
    f();
    zeta::f();
}

void test2()
{
    std::cout << "############ test2" << std::endl;
    using zeta::f; // on importe f() du namespace zeta dans ce scope
    f(); // on utilise le f() importé
    ::f(); // on appelle f() du scope global
}

void test3()
{
    std::cout << "############ test3" << std::endl;
    using namespace zeta;
    // f(); // ambigue
    ::f();
}

void test4()
{
    std::cout << "############ test4" << std::endl;
    f();
    using zeta::f;
    f();

    // using ::f; // ambigue zeta::f et ::f importé dans le scope test4{} 2 f() possibles
    // f();

    {
        using ::f; // ok 1 f() dans test4{}, 1 f() dans ce scope
        f();
    }
}

void test5()
{

}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}
