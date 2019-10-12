//
// Created by benjamin on 12/10/2019.
//

#include "BFS.h"

void BFS::run(BlockWorld *root)
{
    fringe.push(root);
    while (!fringe.empty())
    {
        BlockWorld* current = fringe.front();
        fringe.pop();
        if(isSolution(current))
        {
            print_solution(current);
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

void BFS::print_solution(BlockWorld *node)
{
    if( node->getParent() == nullptr)
    {
        return;
    } else
    {
        std::cout << node->getMove() << ", ";
        print_solution(node->getParent());
    }
}