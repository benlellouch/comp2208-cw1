//
// Created by benjamin on 11/10/2019.
//

#include "Main.h"
#include "BlockWorld.h"
#include "BFS.h"
#include "DFS.h"
#include "IDS.h"

#include <iostream>

bool isSolution(BlockWorld* blockWorld)
{
    std::vector<Block> blocks = blockWorld->getBlocks();

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

std::string direction_to_string(Direction direction)
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

void print_solution(BlockWorld* node)
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

int main(int argc, char *argv[])
{
//    IDS ids(13);
//    ids.run();

    BlockWorld* root = new BlockWorld();
//
//    DFS dfs;
//    dfs.run(root);
    BFS bfs;
    bfs.run(root);

}