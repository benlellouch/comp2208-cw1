//
// Created by benjamin on 11/10/2019.
//

#include "BlockWorld.h"

BlockWorld::BlockWorld() :
parent(nullptr),
player(3,0),
depth(0)
{
    blocks.push_back(Block(0,0,"A"));
    blocks.push_back(Block(1,0,"B"));
    blocks.push_back(Block(2,0,"C"));
    calculate_possible_move();
    calculate_manhattan_distance();
}

BlockWorld::BlockWorld(BlockWorld* parent, Direction direction) :
        parent(parent),
        player(parent->getPlayer()),
        blocks(parent->getBlocks()),
        depth(parent->getDepth() + 1),
        move_taken(direction)
{
    move(direction);
    calculate_possible_move();
    calculate_manhattan_distance();
}

void BlockWorld::calculate_possible_move()
{
    int random = rand() % 4;
//    std::cout << random << "\n";

    if(random == 0 )
    {
        calculate_down();
        calculate_left();
        calculate_up();
        calculate_right();
    }

    if (random == 1 )
    {
        calculate_down();
        calculate_left();
        calculate_right();
        calculate_up();
    }

    if (random == 2)
    {
        calculate_up();
        calculate_right();
        calculate_left();
        calculate_down();
    }

    if (random == 3)
    {
        calculate_left();
        calculate_up();
        calculate_down();
        calculate_right();
    }

    if(random == 4)
    {
        calculate_right();
        calculate_down();
        calculate_up();
        calculate_left();
    }

}

void BlockWorld::calculate_up()
{
    if((player.getY_pos() + 1) < grid_size)
    {
        possible_moves.push_back(up);
    }
}
void BlockWorld::calculate_down()
{
    if((player.getY_pos() - 1) >= 0)
    {
        possible_moves.push_back(down);
    }
}

void BlockWorld::calculate_left()
{
    if((player.getX_pos() - 1) >= 0)
    {
        possible_moves.push_back(left);
    }
}

void BlockWorld::calculate_right()
{
    if((player.getX_pos() + 1) < grid_size)
    {
        possible_moves.push_back(right);
    }

}


void BlockWorld::move(Direction direction)
{
    switch (direction)
    {
        case up:
            move_up();
            break;
        case down:
            move_down();
            break;
        case left:
            move_left();
            break;
        case right:
            move_right();
            break;
    }
}

void BlockWorld::move_up()
{
    int previous_player_y_pos = player.getY_pos();
    player.setY_pos(previous_player_y_pos + 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos() && block->getX_pos() == player.getX_pos())
        {
            block->setY_pos(previous_player_y_pos);
        }
    }
}

void BlockWorld::move_down()
{
    int previous_player_y_pos = player.getY_pos();
    player.setY_pos(previous_player_y_pos - 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos() && block->getX_pos() == player.getX_pos())
        {
            block->setY_pos(previous_player_y_pos);
        }
    }
}

void BlockWorld::move_left()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos - 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos() && block->getX_pos() == player.getX_pos())
        {
            block->setX_pos(previous_player_x_pos);
        }
    }
}


void BlockWorld::move_right()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos + 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos() && block->getX_pos() == player.getX_pos())
        {
            block->setX_pos(previous_player_x_pos);
        }
    }
}

void BlockWorld::calculate_manhattan_distance()
{
    manhattan_distance = 0;

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        std::string name = block->getName();
        int x_pos = block->getX_pos();
        int y_pos = block->getY_pos();

        if(name == "A")
        {
            manhattan_distance += abs(x_pos - 1) + abs(y_pos -2);
            if(x_pos == 1 && y_pos == 2)
            {
                manhattan_distance -= 1;
            }
        }
        if(name == "B")
        {
            manhattan_distance += abs(x_pos -1) + abs(y_pos - 1);
            if(x_pos == 1 && y_pos == 1)
            {
                manhattan_distance -= 1;

            }
        }
        if(name == "C")
        {
            manhattan_distance += abs(x_pos -1) + abs(y_pos - 0);
            if(x_pos == 1 && y_pos == 0)
            {
                manhattan_distance -= 1;

            }
        }
    }

    manhattan_distance += depth;
}