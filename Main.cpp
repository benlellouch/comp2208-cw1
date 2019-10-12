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

    root->move(left);

    std::cout << "The player pos is: " << root->getPlayer().getX_pos() << ", " << root->getPlayer().getY_pos() << "\n";

    std::cout << "The root player pos is: " << root->getPlayer().getX_pos() << ", " << root->getPlayer().getY_pos() << "\n";
    std::cout << "The child player pos is: " << child.getPlayer().getX_pos() << ", " << child.getPlayer().getY_pos() << "\n";
    std::cout << " ---- \n";

    for(Direction direction : child.getPossible_moves())
    {
        switch (direction)
        {
            case up:
                std::cout << "Possible child move: up \n";
                break;
            case down:
                std::cout << "Possible child move: down \n";
                break;
            case left:
                std::cout << "Possible child move: left \n";
                break;
            case right:
                std::cout << "Possible child move: right\n";
                break;
        }

    }

    std::cout << " ---- \n";


    for(Direction direction : root->getPossible_moves())
    {
        switch (direction)
        {
            case up:
                std::cout << "Possible root move: up \n";
                break;
            case down:
                std::cout << "Possible root move: down \n";
                break;
            case left:
                std::cout << "Possible root move: left \n";
                break;
            case right:
                std::cout << "Possible root move: right\n";
                break;
        }
    }

    std::cout << " ---- \n";


    for(Block block : child.getBlocks())
    {
        std::cout << "Block " << block.getName() << " position: " << block.getX_pos() << ", " << block.getY_pos() << " \n";
    }

    std::cout << " ---- \n";

    for(Block block : root->getBlocks())
    {
        std::cout << "Block " << block.getName() << " position: " << block.getX_pos() << ", " << block.getY_pos() << " \n";
    }



    exit(0);
}