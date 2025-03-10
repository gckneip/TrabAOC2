#pragma once 

class Block {
    private:
        int Tag;
        int Counter;
        bool Valid;

    public:
        Block();  

        void Validate();
        bool IsValid() const;
        void SetTag(int tag);
        void AddCounter();
        void ResetCounter();
        bool CompareTag(int tag) const;
        int GetCounter() const;
};
