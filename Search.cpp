//
// Created by benjamin on 22/10/2019.
//

#include "Search.h"

bool Search::check_for_solution(BlockWorld *node)
{
    std::vector<Block> blocks = node->getBlocks();

    int counter = 0;

    for (std::vector<Block>::iterator block_it = blocks.begin() ; block_it != blocks.end() ; ++block_it)
    {
        std::string name = block_it->getName();
        int pos_x = block_it->getX_pos();
        int pos_y = block_it->getY_pos();

//        std::cout << name << " pos x: " << pos_x << " pos y: "<< pos_y << "\n";

        if ( name == "A" && pos_x == 1 && pos_y == 2)
        {
            counter++;
        }
        if (name == "B" && pos_x == 1 && pos_y == 1)
        {
            counter++;
        }
        if (name == "C" && pos_x == 1 && pos_y == 0)
        {
            counter++;
        }

    }

//    std::cout<< "------- \n";

    if(counter == 3)
    {
        return true;
    }

    return false;
}

void Search::print_solution(BlockWorld *node)
{
    if( node->getParent() == nullptr)
    {
        return;
    } else
    {
        std::cout << direction_to_string(node->getMove()) << ", ";
        print_solution(node->getParent());
    }
}


std::string Search::direction_to_string(Direction direction)
{
    switch (direction)
    {
        case up:
            return "up";
        case down:
            return "down";
        case left:
            return "left";
        case right:
            return "right";
    }

    return "unknow direction";
}