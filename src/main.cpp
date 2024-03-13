#include "../include/item.h"
#include "../include/blacksmith.h"
#include <memory>
#include <map>
#include <cctype>

using namespace std;

enum commands {
        CreateSword=1,
        Selection,
        Upgrade,
        InvalidCommand
};

commands resolveCommand(string usr_in) {
    if(usr_in == "create sword")    return CreateSword;
    if(usr_in == "select item")     return Selection;
    if(usr_in == "upgrade")         return Upgrade;

    return InvalidCommand;
 }

int main(int argc, char *argv[]) {

    string usr_in;  
    map<size_t, Item*> usr_inv;

    while(1){
        cout << "Enter what's your move?: ";
        getline(cin >> ws, usr_in);

        switch (resolveCommand(usr_in))
        {
            case CreateSword:
            {
                int in_lvl, in_dmg;
                system("CLS");
                cout << "Enter item parameters:\n";
                cout << "LvL: ";
                cin >> ws >> in_lvl;
                cout << "Damage: ";
                cin >> ws >> in_dmg;

                usr_inv.insert(make_pair(usr_inv.size(), new Item(Item::ITEM_TYPE::SWORD, in_lvl, in_dmg)));
                system("CLS");
                cout << "Sword Created!\n";
                break;
            }
                
            case Selection:
                system("CLS");
                for(const auto& inv_item : usr_inv) {
                    cout << "Item ID: " << inv_item.first << "\n";
                    cout << *(inv_item.second);
                }
                break;

            case Upgrade:
            {
                system("CLS");
                int item_id;
                unique_ptr<Blacksmith> blacksmith(new Blacksmith());

                cout << "Choose item ID: ";
                cin >> ws >> item_id;

                (*blacksmith).give_formula(1);
                (*blacksmith).upgrade_item(*(usr_inv.at(item_id)));
                break;
            }
                
            default:
                cout << "Wrong command.\n";
                break;
            }
    }

    system("CLS");

    return 0;
}