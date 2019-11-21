//
// Created by benjamin on 14/10/2019.
//

#include "DFS.h"

void DFS::run()
{

    fringe.push(Search::get_root());
    increment_number_of_nodes_expanded();
    increment_number_of_nodes_generated();
    while (!fringe.empty())
    {
        BlockWorld* current = fringe.top();
        Player player = current->getPlayer();

        if(get_number_of_nodes_expanded() < 10)
        {
            Search::print_state(current);
        }

        increment_number_of_nodes_expanded();



        fringe.pop();
        if(Search::check_for_solution(current))
        {
            print_solution(current);
            return;
        }

        expand(current);
    }
}

void DFS::expand(BlockWorld *node)
{
    std::vector<Direction> possible_moves = node->getPossible_moves();

    for(std::vector<Direction>::iterator move_it = possible_moves.begin();
        move_it != possible_moves.end();
        ++move_it)
    {
        fringe.push(new BlockWorld(node, *move_it));
        increment_number_of_nodes_generated();
    }
}