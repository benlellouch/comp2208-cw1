//
// Created by benjamin on 19/10/2019.
//

#include "IDS.h"

IDS::IDS(BlockWorld* root, int depth) :
Search(root)
{
    initialize(depth);
}

void IDS::initialize(int depth)
{
   std::cout<<"Depth increased: " << depth << "\n";
    root = get_root();
    max_depth = depth;
    fringe.push(root);
    increment_number_of_nodes_generated();
}

void IDS::run()
{

    while (!fringe.empty())
    {

        BlockWorld* current = fringe.top();
         fringe.pop();
        Player player = current->getPlayer();



        if(current->getDepth() > max_depth)
        {

            if(fringe.empty())
            {
                for (auto& node : garbage)
                {
                    delete node;
                    node = nullptr;
                }
                garbage.erase(std::remove(garbage.begin(), garbage.end(), nullptr), garbage.end());

                initialize(max_depth + 1);
            }
            else if(!(current->is_root()))
            {
                delete current;
            }
        }
        else
        {

            if(get_number_of_nodes_expanded() < 20)
            {
               Search::print_state(current);
            }
            increment_number_of_nodes_expanded();

            if(!(current->is_root()))
            {
                garbage.push_back(current);
            }


            if(Search::check_for_solution(current))
            {
                std::cout << "Solution found:" << '\n';
                print_state(current);
                print_solution(current);
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
