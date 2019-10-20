//
// Created by benjamin on 19/10/2019.
//

#include "AStar.h"

void AStar::run(BlockWorld *root)
{
    int number_of_nodes = 0;
    std::cout << "Start ----- \n";

    fringe.push(root);
    while (!fringe.empty())
    {
        BlockWorld* current = fringe.top();
//        fringe.pop();
        Player player = current->getPlayer();

        number_of_nodes ++;

        if (current->getParent() != nullptr)
        {
            if(number_of_nodes < 100)
            {
                BlockWorld* parent = current->getParent();
                Player parent_player = parent->getPlayer();
                std::cout << "Node number: " << number_of_nodes;
                std::cout << " Distance from Solution: " << current->getManhattan_distance();
                std::cout << " Player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() << " with parent pos x: " << parent_player.getX_pos() << " pos y: " << parent_player.getY_pos() << "  and depth of " << parent->getDepth() <<  "\n";
            }


        }

        fringe.pop();
        if(isSolution(current))
        {
            std::cout << "The solution is: ";
            print_solution(current);
            std::cout<< "\n";
            std::cout << "Total number of nodes expanded: " << number_of_nodes << "\n";
            std::cout << "Depth of solution: " << current->getDepth();
            return;
        }

        expand(current);
    }
}

void AStar::expand(BlockWorld *node)
{
    std::vector<Direction> possible_moves = node->getPossible_moves();

    for(std::vector<Direction>::iterator move_it = possible_moves.begin();
        move_it != possible_moves.end();
        ++move_it)
    {
        fringe.push(new BlockWorld(node, *move_it));
    }
}
