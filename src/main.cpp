#include "../include/item.h"
#include "../include/blacksmith.h"
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {

    Blacksmith blacksmith;
    unique_ptr<Item> testSword(new Item(Item::ITEM_TYPE::SWORD, 1, 4));
    //Item testSword(Item::ITEM_TYPE::SWORD, 1, 4);
    
    blacksmith.give_formula(2);

    for (size_t i = 0; i < 4; i++)
    { 
        cout << *testSword;
        blacksmith.upgrade_item(*testSword); 
    }

    return 0;
}