#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>  
#include "../address.hpp"
#include "../block.hpp"
#include "../cache.hpp"
#include <iomanip>
#include <cstdint>


int main(int argc, char* argv[]) {
    if (argc != 7) {  
        std::cerr << "Erro: Espera-se 7 argumentos\n";
        return 1;
    }
        int nsets = std::stoi(argv[1]);
        int bsize = std::stoi(argv[2]);
        int assoc = std::stoi(argv[3]);

        if( nsets <= 0 || bsize <= 0 || assoc <= 0){
            std::cerr << "Erro: Nenhum dos argumentos pode ser 0\n";
            return 1;
        }

        if(argv[5][0] != '0' && argv[5][0] != '1'){
            std::cerr << "Erro: Argumento de saída deve ser 0 ou 1\n";
            return 1;
        }

    std::ifstream file(argv[6], std::ios::binary);
    if (!file) {
        std::cerr << "Erro ao abrir arquivo!\n";
        return 1;
    }

    unsigned char buffer[4];
    char policy = argv[4][0]; 
    Address address = Address(); 
    uint32_t tag = 0;
    uint32_t indice = 0;
    uint32_t offset = 0;
    uint32_t offset_bits = static_cast<int>(std::log2(bsize)); 
    uint32_t index_bits = static_cast<int>(std::log2(nsets)); 
    Cache cache = Cache(nsets, assoc, policy);

    int totalAccesses = 0;
    while(file.read(reinterpret_cast<char*>(buffer), sizeof(buffer))){
        uint32_t palavra = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);    

        offset = palavra & ((1 << offset_bits) - 1);
        indice = (palavra >> offset_bits) & ((1U << index_bits) - 1);
        tag = palavra >> (offset_bits + index_bits);
        address.Update(tag, indice, offset);

        cache.FindBlock(address);

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
    std::cout << std::setw(30) << std::left << "Métrica" << std::setw(20) << std::left << "Valor" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    std::cout << std::setw(30) << std::left << "Total de acessos:" << std::setw(20) << totalAccesses << std::endl;
    std::cout << std::setw(30) << std::left << "Total de Misses:" << std::setw(20) << totalMiss << std::endl;
    std::cout << std::setw(30) << std::left << "Hit Rate:" << std::setw(20) << hitRate << std::endl;
    std::cout << std::setw(30) << std::left << "Miss Rate:" << std::setw(20) << missRate << std::endl;
    std::cout << std::setw(30) << std::left << "Compulsory Miss Rate:" << std::setw(20) << compulsoryMissRate << std::endl;
    std::cout << std::setw(30) << std::left << "Capacity Miss Rate:" << std::setw(20) << capacityMiss << std::endl;
    std::cout << std::setw(30) << std::left << "Conflict Miss Rate:" << std::setw(20) << conflictMissRate << std::endl; 
    } else {
        std::cout << std::fixed << std::setprecision(4);
        std::cout << totalAccesses << ", " 
                << hitRate << ", " 
                << missRate << ", ";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << compulsoryMissRate << ", " 
                << capacityMissRate << ", " 
                << conflictMissRate << std::endl;    
    }
    return 0;

}