//
// Created by benjamin on 12/10/2019.
//

#include "BFS.h"

void BFS::run(BlockWorld *root)
{
    int number_of_nodes = 0;
    std::cout << "Start ----- \n";

    fringe.push(root);
    while (!fringe.empty())
    {
        BlockWorld* current = fringe.front();
        Player player = current->getPlayer();

        number_of_nodes ++;

        if (current->getParent() != nullptr)
        {
            BlockWorld* parent = current->getParent();
            Player parent_player = parent->getPlayer();
            std::cout << "Node number: " << number_of_nodes;
            std::cout << " Player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() << " with parent pos x: " << parent_player.getX_pos() << " pos y: " << parent_player.getY_pos() <<  "\n";

        }

        fringe.pop();
        if(isSolution(current))
        {
            std::cout << "The solution is: ";
            print_solution(current);
            std::cout<< "\n";
            std::cout << "Total number of nodes expanded: " << number_of_nodes << "\n";
            return;
        }

        expand(current);
    }
}

void BFS::expand(BlockWorld *node)
{
    std::vector<Direction> possible_moves = node->getPossible_moves();

    for(std::vector<Direction>::iterator move_it = possible_moves.begin();
        move_it != possible_moves.end();
        ++move_it)
    {
        fringe.push(new BlockWorld(node, *move_it));
    }
}

