#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>

enum class Politic {
    RANDOM = 'R',
    LRU = 'L',
    FIFO = 'F'
};

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    if (argc < 4) {  // Need at least 4 arguments (program name + 3 numbers)
    std::cerr << "Error: Expected at least 3 arguments.\n";
    return 1;
}

        char* end = nullptr;
        long nsets = std::stoi(argv[1]);
        long bsize = std::stoi(argv[2]);
        long assoc = std::stoi(argv[3]);
    
    std::cout << "numero de conjuntos: " << nsets << std::endl;
    std::cout << "numero de bits de offset: " << bsize <<std::endl;
    std::cout << "associatividade de " << assoc << " vias" << std::endl;

    Politic myPolitic = static_cast<Politic>(argv[4][0]);  
    std::cout << (char)myPolitic;

    std::ifstream file(argv[6], std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    char buffer[4];
    file.read(buffer, sizeof(buffer));

    int palavra = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);    

    std::cout << "a" << palavra << "a";

    file.close();
    return 0;

}
