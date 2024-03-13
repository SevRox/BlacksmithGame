#ifndef item_H
#define item_H
#include <iostream>
#include <cstdint>

class Item {

    public:

        enum ITEM_TYPE {SWORD=1, ARMOR};

        Item(ITEM_TYPE t, uint8_t u, uint8_t l, uint8_t d) 
        :   _type(t), 
            _upgrade(u),
            _lvl(l),
            _dmg(d)
        {}

        Item(ITEM_TYPE t, uint8_t l, uint8_t d) 
        :   _type(t), 
            _upgrade(0),
            _lvl(l),
            _dmg(d)
        {}

        ~Item() {}

        int get_upgrade() {
            return _upgrade;
        }

        void upgrade_item(uint8_t _upgrade_formula_value) {
            for (size_t i = 0; i < _upgrade_formula_value; i++) {
                this->_dmg += (++_upgrade);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Item& i)
        {
            return os << "Type: " 
            << +i._type << " +" 
            << +i._upgrade << "\nLVL: " 
            << +i._lvl << "\nDMG: " 
            << +i._dmg << "\n\n";
        }

    private:    
        ITEM_TYPE _type;
        uint8_t _upgrade;
        uint8_t _lvl;
        uint8_t _dmg;
    
};

#endif
