#include <iostream>
#include <functional>

int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }

class MyClass {
public:
    std::function<int(int, int)> operation;

    MyClass(char type) {
        switch (type) {
            case 'R': operation = add; break;
            case 'F': operation = multiply; break;
            default:
                operation = [](int, int) { return 0; };
                std::cerr << "Invalid type! Using default function." << std::endl;
                break;
        }
    }

    void execute(int a, int b) {
        std::cout << "Result: " << operation(a, b) << std::endl;
    }
};

int main() {
    MyClass objR('R');
    objR.execute(5, 3); // Output: 8

    MyClass objF('F');
    objF.execute(5, 3); // Output: 15

    return 0;
}