//
// Created by benjamin on 19/10/2019.
//

#include "IDS.h"

IDS::IDS(BlockWorld* root, int depth) :
Search(root),
expanded_nodes(0)
{
    initialize(depth);
}

void IDS::initialize(int depth)
{
    root = get_root();
    max_depth = depth;
    fringe.push(root);
}

void IDS::run()
{
//    std::cout << "Start ----- \n";


    while (!fringe.empty())
    {

        BlockWorld* current = fringe.top();
        fringe.pop();
        Player player = current->getPlayer();

        if(current->getDepth() > max_depth)
        {
            if(fringe.empty())
            {
//                std::cout << "I get to this part";
                initialize(max_depth + 1);
            }
        } else
        {
            if (current->getParent() != nullptr)
            {
//                BlockWorld* parent = current->getParent();
//                Player parent_player = parent->getPlayer();
//                std::cout << "Node number: " << expanded_nodes;
//                std::cout << " Depth: " << current->getDepth();
//                std::cout << " Player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() << " with parent pos x: " << parent_player.getX_pos() << " pos y: " << parent_player.getY_pos() << "  and depth of " << parent->getDepth() <<  "\n";

            }else
            {
//                std::cout << "Node number: " << expanded_nodes;
//                std::cout << " Depth: " << current->getDepth();
//                std::cout << " Player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() <<  "\n";
            }



            expanded_nodes ++;
            if(Search::check_for_solution(current))
            {
//            std::cout << "The solution is: ";
//            Search::print_solution(current);
//            std::cout<< "\n";
            std::cout << get_number_of_nodes_generated() << "\n";
                return;
            }

            expand(current);
        }



    }
}

void IDS::expand(BlockWorld *node)
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