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


    if(counter == 3)
    {
        return true;
    }

    return false;
}

void Search::print_solution(BlockWorld *node)
{
    if( node->is_root())
    {
        std::cout << "The solution is: ";

        while (!solution_stack.empty())
        {
            BlockWorld* top = solution_stack.top();
            std::cout << direction_to_string(top->getMove()) << ", ";
            solution_stack.pop();
        }
        std::cout <<"\n Number of nodes generated: " << get_number_of_nodes_generated() << "\n";
        return;
    } else
    {
        solution_stack.push(node);
        print_solution(node->getParent());
    }
}

void Search::print_state(BlockWorld *node)
{
    Player player = node->getPlayer();
    std::vector<Block> blocks = node->getBlocks();
    bool pos_used;
    if(node->is_root())
    {
        std::cout << "Node number: " << get_number_of_nodes_expanded() << " at depth : " << node->getDepth() << " with player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() <<" this is the root"<<  "\n";
    }
    else
    {
        Player parent_player = node->getParent()->getPlayer();
        std::cout << "Node number: " << get_number_of_nodes_expanded() << " at depth : " << node->getDepth() << " with player pos x: " << player.getX_pos() << " pos y: " << player.getY_pos() << " with parent pos x: " << parent_player.getX_pos() << " pos y: " << parent_player.getY_pos() <<  "\n";
    }

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            pos_used = false;
            if(player.getX_pos() == j && player.getY_pos() == i)
            {
                std::cout<<"*";
                pos_used = true;
            }
            for (std::vector<Block>::iterator block_it = blocks.begin() ; block_it != blocks.end() ; ++block_it)
            {
                if(block_it->getX_pos() == j && block_it->getY_pos() == i)
                {
                    std::cout<< block_it->getName();
                    pos_used = true;
                }
            }
            if(!pos_used)
            {
                std::cout<<"-";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<" \n";
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

    return "unknown direction";
}