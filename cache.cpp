#include <vector>
#include <functional>
#include <iostream>
#include "block.hpp"
#include "address.hpp"


class Cache {
    private:
        std::vector<std::vector<Block>> Blocos;
        std::function<void(Cache&, Address&)> SubstitutionPolicy;
        int CompulsoryMiss;
        int ConflictMiss;
        int CapacityMiss;

    public:
        Cache(int n_sets, int assoc, char policy){
            Blocos.resize(n_sets);
            for(int i = 0; i < n_sets; i++){
                Blocos[i].resize(assoc);
            }
            switch (policy){
                case 'R' : SubstitutionPolicy = RandomPolicy; break;
                case 'L' : SubstitutionPolicy = LRU; break;
                case 'F' : SubstitutionPolicy = FIFO; break;
                default: std::cerr << "Política de substituição inválida" << std::endl;
                break;
            }

        }

        Cache(int n_sets){
            Blocos.resize(n_sets);
        }

        bool FindBlock(Address address){
        }



        void TreatMiss(Address address, int tag){
            Blocos[address.GetIndex()][tag].Validate();
            Blocos[address.GetIndex()][tag].SetTag(address.GetTag());
        }
};


void RandomPolicy(Cache& cache, Address& address){return;};
void LRU(Cache& cache, Address& address){return;};
void FIFO(Cache& cache, Address& address){return;};
