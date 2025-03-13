#pragma once 
#include <cstdint>

class Block {
    private:
        uint32_t Tag;        
        bool Valid;

    public:
        Block();  

        void Validate();
        bool IsValid() const;
        void SetTag(uint32_t tag);
        bool CompareTag(uint32_t tag) const;
};
