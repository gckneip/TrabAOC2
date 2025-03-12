#include <vector>
#include <deque>
#include <functional>
#include <iostream>
#include "../cache.hpp"
#include "../block.hpp"
#include "../address.hpp"

Cache::Cache(int n_sets, int assoc, char policy){
    Blocos.resize(n_sets);
    for(int i = 0; i < n_sets; i++){
        Blocos[i].resize(assoc);
    }
    switch (policy){
        case 'R' : SubstitutionPolicy = Random; Hit = [](Cache, Address, int) {}; break;
        case 'L' : SubstitutionPolicy = LRU; Hit = HitLRU; break;
        case 'F' : SubstitutionPolicy = FIFO; Hit = [](Cache, Address, int) {}; break;
        default: std::cerr << "Política de substituição inválida" << std::endl;
        break;
    }

}

void Cache::FindBlock(Address address){
    int index = address.GetIndex();
    int assoc = Blocos[index].size();
    for(int i = 0; i <= Blocos[index].size(); i++){
        if(!Blocos[index][i].IsValid()){
            CompulsoryMiss++;
            TreatMiss(&Blocos[index][i], address.GetTag());
            return;
        } else {
            if(Blocos[index][i].CompareTag(address.GetTag())){
                Hit(*this, address, i);
                return;
            } 
        }
    }
    SubstitutionPolicy(*this, address);
    if (assoc > 1){
        CapacityMiss++;
    } else {
        ConflictMiss++;
    }
}

void Cache::TreatMiss(Block* bloco, int tag){
    bloco->Validate();
    bloco->SetTag(tag);
}

std::deque<Block> *Cache::GetBlocos (int index){
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


void Random(Cache& cache, Address address){
    std::deque<Block>* vias = cache.GetBlocos(address.GetIndex()); //um ponteiro para uma fila
    Block* currentBlock = &(*vias)[random() % (vias->size())];
    cache.TreatMiss(currentBlock, address.GetTag());
    return;
    };

void FIFO(Cache& cache, Address address){
    std::deque<Block>* vias = cache.GetBlocos(address.GetIndex()); //um ponteiro para uma fila
    Block newBlock = vias->front();
    cache.TreatMiss(&newBlock, address.GetTag());
    vias->push_back(newBlock);
    vias->pop_front();
    return;
};

void LRU(Cache& cache, Address address){
    FIFO(cache, address);
    return;
};

void HitLRU(Cache& cache, Address address, int via){
    std::deque<Block>* vias = cache.GetBlocos(address.GetIndex()); //um ponteiro para uma fila
    auto it = vias->begin()+via;
    Block temp = *it;
    vias->erase(it);
    vias->push_back(temp);
}

