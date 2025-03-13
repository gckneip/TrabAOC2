#include <vector>
#include <deque>
#include <functional>
#include <iostream>
#include "../cache.hpp"
#include "../block.hpp"
#include "../address.hpp"
#include <cstdint>

Cache::Cache(int n_sets, int assoc, char policy): 
CompulsoryMiss(0), ConflictMiss(0), CapacityMiss(0){
    Blocos.resize(n_sets);
    for(int i = 0; i < n_sets; i++){
        Blocos[i].resize(assoc);
    }
    switch (policy){
        case 'R' : SubstitutionPolicy = Random; Hit = [](Cache*, Address, int) {}; break;
        case 'L' : SubstitutionPolicy = LRU; Hit = HitLRU; break;
        case 'F' : SubstitutionPolicy = FIFO; Hit = [](Cache*, Address, int) {}; break;
        default: std::cerr << "Política de substituição inválida" << std::endl;
        break;
    }

}

void Cache::FindBlock(Address address){
    int index = address.GetIndex();
    for(size_t i = 0; i < Blocos[index].size(); i++){
        if(!Blocos[index][i].IsValid()){
            CompulsoryMiss++;
            TreatMiss(&(Blocos[index][i]), address.GetTag());
            return;
        } else {
            if(Blocos[index][i].CompareTag(address.GetTag())){
                Hit(this, address, i);
                return;
            } 
        }
    }
    SubstitutionPolicy(this, address);
    if (IsCacheFull()){
        CapacityMiss++;
        return;
    } else {
        ConflictMiss++;
        return;
    }
}

void Cache::TreatMiss(Block* bloco, uint32_t tag){
    bloco->Validate();
    bloco->SetTag(tag);
}

std::deque<Block> *Cache::GetBlocos (uint32_t index){
    return &Blocos[index];
}

int Cache::GetMissCompulsory() const {
    return CompulsoryMiss;
};
int Cache::GetMissConflict() const{
    return ConflictMiss;
};
int Cache::GetMissCapacity() const{
    return CapacityMiss;
};

bool Cache::IsCacheFull() {
    for (const auto& set : Blocos) { 
        for (const auto& block : set) {  
            if (!block.IsValid()) {  
                return false;  
            }
        }
    }
    return true; 
}


void Random(Cache *cache, Address address){
    std::srand(1);
    std::deque<Block>* vias = cache->GetBlocos(address.GetIndex()); 
    Block* currentBlock = &(*vias)[std::rand() % (vias->size())];
    cache->TreatMiss(currentBlock, address.GetTag());
    return;
    };

void FIFO(Cache* cache, Address address){
    std::deque<Block>* vias = cache->GetBlocos(address.GetIndex());
    Block newBlock = Block();
    cache->TreatMiss(&newBlock, address.GetTag());
    vias->pop_front();
    vias->push_back(newBlock);
    return;
};

void LRU(Cache *cache, Address address){
    FIFO(cache, address);
    return;
};

void HitLRU(Cache *cache, Address address, int via){
    std::deque<Block>* vias = cache->GetBlocos(address.GetIndex()); 
    auto it = vias->begin()+via;
    Block temp = *it;
    vias->erase(it);
    for(size_t i = 0; i < vias->size(); i++){
        if(!((*vias)[i].IsValid())){
            (*vias)[i] = temp;
            return;
        } else {
            vias->push_back(temp);
            return;
        }
    }
}