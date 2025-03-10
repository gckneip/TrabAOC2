#include <vector>
#include "block.hpp"
#include "address.hpp"

class Cache {
    private:
        std::vector<std::vector<Block>> Blocos;
        int CompulsoryMiss;
        int ConflictMiss;
        int CapacityMiss;

    public:
        Cache(int n_sets, int assoc){
            Blocos.resize(n_sets);
            for(int i = 0; i < n_sets; i++){
                Blocos[i].resize(assoc);
            }
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
                    Blocos[address.GetIndex()][i].Validate();
                    Blocos[address.GetIndex()][i].SetTag(address.GetTag()); 
                    Blocos[address.GetIndex()][i].ResetCounter();
                    return false;
                }
            }
        }



};