#pragma once
#include <cstdint>

class Address {
    private:
        uint32_t Tag;
        uint32_t Index;
        uint32_t Offset;
    public:
    
    Address();

    void Update(uint32_t tag, uint32_t index, uint32_t offset); 
    uint32_t GetTag() const;
    uint32_t GetIndex() const;    
};