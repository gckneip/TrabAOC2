#pragma once 
#include <iostream>

class Block {
    private:
        u_int32_t Tag;        
        bool Valid;

    public:
        Block();  

        void Validate();
        bool IsValid() const;
        void SetTag(u_int32_t tag);
        bool CompareTag(u_int32_t tag) const;
};
