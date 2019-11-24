//
// Created by benjamin on 19/10/2019.
//

#include "AStar.h"

void AStar::run()
{

    fringe.push(Search::get_root());
    Search::increment_number_of_nodes_generated();
    increment_number_of_nodes_expanded();

    while (!fringe.empty())
    {
        BlockWorld* current = fringe.top();
        Player player = current->getPlayer();


        if(get_number_of_nodes_expanded() < 10)
        {
//            Search::print_state(current);
        }

        increment_number_of_nodes_expanded();

        fringe.pop();
        if(Search::check_for_solution(current))
        {
//            print_state(current);
            print_solution(current);
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
        Search::increment_number_of_nodes_generated();
    }
}
