#include <vector>
#include "block.hpp"
#include "address.hpp"
#include "politic.cpp"

class Cache {
    private:
        std::vector<std::vector<Block>> Blocos;
        int CompulsoryMiss;
        int ConflictMiss;
        int CapacityMiss;
        Politic Politica;

    public:
        Cache(int n_sets, int assoc, Politic politica){
            Blocos.resize(n_sets);
            for(int i = 0; i < n_sets; i++){
                Blocos[i].resize(assoc);
            }

            Politica = politica;
        }

        Cache(int n_sets){
            Blocos.resize(n_sets);
        }

        bool FindBlock(Address address){
            
            for (int i = 0; i < Blocos[address.GetIndex()].size(); i++){
                if(Blocos[address.GetIndex()][i].IsValid()){
                    if(Blocos[address.GetIndex()][i].CompareTag(address.GetTag())){
                        Blocos[address.GetIndex()][i].ResetCounter();
                        return true;
                    } else {
                        Blocos[address.GetIndex()][i].AddCounter();
                    }
                } else {
                    CompulsoryMiss++;
                    TreatMiss(address, i);
                    return false;
                }
            }
        }

        void TreatMiss(Address address, int tag){
            Blocos[address.GetIndex()][tag].Validate();
            Blocos[address.GetIndex()][tag].SetTag(address.GetTag());
            Blocos[address.GetIndex()][tag].ResetCounter();
        }
};