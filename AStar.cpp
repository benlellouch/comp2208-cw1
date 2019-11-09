//
// Created by benjamin on 19/10/2019.
//

#include "AStar.h"

void AStar::run()
{
//    std::cout << "Start ----- \n";

    fringe.push(Search::get_root());
    Search::increment_number_of_nodes_generated();
    while (!fringe.empty())
    {
        BlockWorld* current = fringe.top();
        Player player = current->getPlayer();


        if (current->getParent() != nullptr)
        {
            if(get_number_of_nodes_generated() < 100)
            {
//                BlockWorld* parent = current->getParent();
//                Player parent_player = parent->getPlayer();
//                std::cout << "Node number: " << get_number_of_nodes_generated();
//                std::cout << " Distance from Solution: " << current->getManhattan_distance();
//                std::cout << " Player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() << " with parent pos x: " << parent_player.getX_pos() << " pos y: " << parent_player.getY_pos() << "  and depth of " << parent->getDepth() <<  "\n";
            }


        }

        fringe.pop();
        if(Search::check_for_solution(current))
        {
//            std::cout << "The solution is: ";
//            Search::print_solution(current);
//            std::cout<< "\n";
//            std::cout << "Total number of nodes expanded: " << Search::get_number_of_nodes_generated() << "\n";
//            std::cout << "Depth of solution: " << current->getDepth();
            std::cout << get_number_of_nodes_generated() << "\n";
//
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
