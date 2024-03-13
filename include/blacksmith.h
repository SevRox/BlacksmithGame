#ifndef blacksmith_H
#define blacksmith_H
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "../include/item.h"

class Blacksmith {
    public:
        Blacksmith() : 
            _upgrade_formula(false),
            _tincture_potion(false),
            _luck_boost(false),
            _luck_boost_value(0.0),
            _upgrade_formula_value(0.0)
        {
            srand(time(NULL));
        }
        ~Blacksmith(){} 

        void upgrade_item(Item & item){
            // look at memebers to see if stats are changed
            // get_sucess rate
            // change memebrs to false
            if (!_upgrade_formula) {
                std::cout << "Upgrade formula required. \n";
                return;
            } 
            
            if(item.get_upgrade() < 9) {
                if(get_success_rate() < +SUCCES_RATES[item.get_upgrade()]) {
                    std::cout << "Upgrade Succesful! \n";
                    item.upgrade_item(_upgrade_formula_value) ;
                    std::cout << item;
                } else {
                    std::cout << "Upgrade Failed! \n";
                    item.~Item();
                }
                 

                clear_blacksmith_inv();
            } else {
                std::cout << "MAX UPGRADE!\n";
            }
        }

        void give_formula(uint8_t _upgrade_formula_val) {
            this->_upgrade_formula_value = _upgrade_formula_val;
            this->_upgrade_formula = true;
        }

    private:
        bool _upgrade_formula;
        bool _tincture_potion;
        bool _luck_boost;
        float _luck_boost_value;
        float _upgrade_formula_value;
        uint8_t SUCCES_RATES[9] {100, 90, 80, 70, 50, 33, 25, 20, 12};

        /*Upgrade rates:
            +1  100
            +2  90
            +3  80
            +4  70
            +5  50
            +6  33
            +7  25
            +8  20
            +9  12
            */

        int get_success_rate() {
            int rnd = rand() % 100;
            // std::cout << rnd << '\n';
            return rnd;
        }

        void clear_blacksmith_inv() {
            this->_upgrade_formula = false;
            this->_upgrade_formula_value = 0;
        }

};

#endif