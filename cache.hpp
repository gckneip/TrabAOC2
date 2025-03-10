#include <vector>
#include "block.hpp"
#include "address.hpp"

class Cache {
    private:
        std::vector<std::vector<Block>> Blocos;

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

        void FindBlock(Address address){
            
        }

};