#include "../address.hpp"

Address::Address(){};

int Address::GetTag() const { return Tag; };
int Address::GetIndex() const { return Index; };
void Address::Update(int tag, int index, int offset){
    Tag = tag;
    Index = index;
    Offset = offset;
}
