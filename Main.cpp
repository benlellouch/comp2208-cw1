//
// Created by benjamin on 11/10/2019.
//

#include "Main.h"
#include "BlockWorld.h"

#include <iostream>

int main(int argc, char *argv[])
{
    BlockWorld* root = new BlockWorld();
    BlockWorld child(root, left);
    std::cout << "The player pos is: " << root->getPlayer().getX_pos() << ", " << root->getPlayer().getY_pos() << "\n";
    root->move(up);
    child.move(up);
    child.move(left);
    std::cout << "The player pos is: " << root->getPlayer().getX_pos() << ", " << root->getPlayer().getY_pos() << "\n";
    std::cout << "The player pos is: " << child.getPlayer().getX_pos() << ", " << child.getPlayer().getY_pos() << "\n";

    exit(0);
}