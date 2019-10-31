//
// Created by benjamin on 11/10/2019.
//

#include "Main.h"
#include "BlockWorld.h"
#include "BFS.h"
#include "DFS.h"
#include "IDS.h"
#include "AStar.h"

#include <iostream>

int main(int argc, char *argv[])
{
    IDS ids(new BlockWorld(), 12);
    ids.run();
}
