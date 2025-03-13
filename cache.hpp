#include <vector>
#include <deque>
#include <functional>
#include "block.hpp"
#include "address.hpp"
#include <cstdint>

class Cache;

void Random(Cache* cache, Address address);
void FIFO(Cache* cache, Address address);
void LRU(Cache* cache, Address address);

void HitLRU(Cache* cache, Address address, int via);

class Cache {
    private:
        std::vector<std::deque<Block>> Blocos;
        std::function<void(Cache*, Address)> SubstitutionPolicy;
        std::function<void(Cache*, Address, int)> Hit;
        int CompulsoryMiss;
        int ConflictMiss;
        int CapacityMiss;
    public:
        Cache(int n_sets, int assoc, char policy);

        void FindBlock(Address address);
        void TreatMiss(Block* bloco, uint32_t tag);
        std::deque<Block> *GetBlocos (uint32_t index);
        int GetMissCompulsory() const;
        int GetMissConflict() const;
        int GetMissCapacity() const;
        bool IsCacheFull(); 
};