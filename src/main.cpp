#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include "../address.hpp"
#include "../block.hpp"
#include "../cache.hpp"


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
        int nsets = std::stoi(argv[1]);
        int bsize = std::stoi(argv[2]);
        int assoc = std::stoi(argv[3]);

    std::cout << "numero de conjuntos: " << nsets << std::endl;
    std::cout << "numero de bits de offset: " << bsize <<std::endl;
    std::cout << "associatividade de " << assoc << " vias" << std::endl;



    std::ifstream file(argv[6], std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    char buffer[4];
    char policy = argv[4][0]; 
    Address address = Address(); //criar construtor vazio
    int tag = 0;
    int indice =0;
    int offset = 0;
    
    Cache cache = Cache(nsets, assoc, policy);//modificar cache.hpp

    int totalAccesses = 0;
    while(file.read(buffer, sizeof(buffer))){
    
    int palavra = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);    
    //encontrar tag, índice e offset
    address.Update(tag, indice, offset);

    cache.FindBlock(address);

    std::cout << palavra << " ";
    totalAccesses++;
    }
    file.close();

    int compulsoryMiss =cache.GetMissCompulsory();
    int conflitMiss = cache.GetMissConflict();
    int capacityMiss = cache.GetMissCapacity();

    int totalMiss = compulsoryMiss + conflitMiss + capacityMiss;

    int totalHits = totalAccesses - totalMiss;

    float hitRate = totalHits/totalAccesses;
    float missRate = totalMiss/totalAccesses;
    float compulsoryMissRate = compulsoryMiss/totalMiss;
    float conflictMissRate = conflitMiss/totalMiss;
    float capacityMissRate = capacityMiss/totalMiss;

    if (argv[5][0] == '0'){
        //formato livre
    } else {
        std::cout << totalAccesses << ", " << hitRate << ", " << missRate << ", " << compulsoryMiss << ", " << conflictMissRate << ", " << capacityMissRate << std::endl;
    }
    return 0;

}
