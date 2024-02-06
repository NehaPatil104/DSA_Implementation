#include <iostream>

class MyClass {
public:
    static void staticFunction() {
        std::cout << "This is a static member function." << std::endl;
    }
};

int main() {
    // Accessing the static member function directly using the class name.
    MyClass::staticFunction();

    return 0;
}
