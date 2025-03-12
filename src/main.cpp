#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>  
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
        int nsets = std::stoi(argv[1]);
        int bsize = std::stoi(argv[2]);
        int assoc = std::stoi(argv[3]);

    std::cout << "numero de conjuntos: " << nsets << std::endl;
    std::cout << "numero de bytes em um bloco: " << bsize <<std::endl;
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
    int indice = 0;
    int offset = 0;
    int offset_bits = static_cast<int>(std::log2(bsize)); // For 64-byte blocks, offset_bits = 6
    int index_bits = static_cast<int>(std::log2(nsets)); // For 16 sets, index_bits = 4
    Cache cache = Cache(nsets, assoc, policy);//modificar cache.hpp

    std::cout << "bits de offset: " << offset_bits;
    std::cout << "\nbits de índice: " << index_bits << "\n";
    int totalAccesses = 0;
    while(file.read(buffer, sizeof(buffer))){
    
    int palavra = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);    
    
    //encontrar tag, índice e offset
    offset = palavra & ((1 << offset_bits) - 1);
    indice = (palavra >> offset_bits) & ((1 << index_bits) - 1);
    tag = palavra >> (offset_bits + index_bits);
    address.Update(tag, indice, offset);

    cache.FindBlock(address);

   // std::cout << palavra << " ";
    totalAccesses++;
    }
    file.close();

    int compulsoryMiss = cache.GetMissCompulsory();
    int conflitMiss = cache.GetMissConflict();
    int capacityMiss = cache.GetMissCapacity();

    int totalMiss = compulsoryMiss + conflitMiss + capacityMiss;

    int totalHits = totalAccesses - totalMiss;

    float hitRate = (float)totalHits/(float)totalAccesses;
    float missRate = (float)totalMiss/(float)totalAccesses;
    float compulsoryMissRate = (float)compulsoryMiss/(float)totalMiss;
    float conflictMissRate = (float)conflitMiss/(float)totalMiss;
    float capacityMissRate = (float)capacityMiss/(float)totalMiss;

    if (argv[5][0] == '0'){
        std::cout 
        << "\nTotal de acessos: " << totalAccesses 
        << "\nTotal de Misses: " << totalMiss 
        << "\nHit Rate: " << hitRate 
        << "\nMiss Rate: " << missRate 
        << "\nCompulsory Miss Rate: " << compulsoryMissRate 
        << "\nConflict Miss Rate: " << capacityMissRate 
        << "\nCapacity Miss Rate: " << conflictMissRate << std::endl;
    } else {
        std::cout << totalAccesses << ", " << hitRate << ", " << missRate << ", " << std::round(compulsoryMissRate * 100) / 100 << ", " << std::round(capacityMissRate * 100) / 100 << ", " << std::round(conflictMissRate * 100) / 100 << std::endl;
    }
    return 0;

}