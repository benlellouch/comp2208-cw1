//
// Created by benjamin on 11/10/2019.
//

#include "Main.h"
#include "BlockWorld.h"
#include "BFS.h"
#include "DFS.h"
#include "IDS.h"
#include "AStar.h"



int main(int argc, char *argv[])
{
    if (( atoi(argv[2]) > 18) || (atoi(argv[2]) < 1) ) {
      std::cerr << "Please input a depth between 1 and 18 \n";
    }
    std::vector<BlockWorld*> config;
    config.push_back(new BlockWorld(1,2 , 2,2 , 1,1 , 1,0 )); // 1
    config.push_back(new BlockWorld(0,2 , 2,2 , 1,1 , 1,0 )); // 2
    config.push_back(new BlockWorld(0,1 , 2,2 , 1,1 , 1,0 )); // 3
    config.push_back(new BlockWorld(0,0 , 2,2 , 1,1 , 1,0 )); // 4
    config.push_back(new BlockWorld(3,0 , 1,3 , 1,2 , 1,1 )); // 5
    config.push_back(new BlockWorld(1,1 , 1,3 , 2,2 , 1,0 )); // 6
    config.push_back(new BlockWorld(1,0 , 1,3 , 2,2 , 1,1 )); // 7
    config.push_back(new BlockWorld(2,0 , 1,3 , 1,2 , 2,1 )); // 8
    config.push_back(new BlockWorld(3,0 , 1,3 , 1,2 , 2,1 )); // 9
    config.push_back(new BlockWorld(0,0 , 3,2 , 1,1 , 1,0 )); // 10
    config.push_back(new BlockWorld(1,2 , 1,3 , 2,2 , 2,1 )); // 11
    config.push_back(new BlockWorld(0,0 , 1,3 , 1,2 , 3,0 )); // 12
    config.push_back(new BlockWorld(2,3 , 2,2 , 1,3 , 2,0 )); // 13
    config.push_back(new BlockWorld(3,3 , 2,2 , 1,3 , 2,0 )); // 14
    config.push_back(new BlockWorld(1,0 , 2,2 , 2,1 , 2,0 )); // 15
    config.push_back(new BlockWorld(0,0 , 2,2 , 2,1 , 2,0 )); // 16
    config.push_back(new BlockWorld(1,0 , 2,2 , 2,3 , 3,0 )); // 17
    config.push_back(new BlockWorld(0,0 , 2,2 , 2,3 , 3,0 )); // 18


    int depth = atoi(argv[2]) - 1;

    if(strcmp(argv[1],"BFS") == 0)
    {
        BFS bfs(config[depth]);
        bfs.run();
    }
    else if (strcmp(argv[1],"DFS") == 0)
    {
        DFS dfs(config[depth]);
        dfs.run();
    }
    else if (strcmp(argv[1],"IDS") == 0)
    {
        IDS ids(config[depth],0);
        ids.run();
    }
    else if (strcmp(argv[1],"ASTAR") == 0)
    {
        AStar aStar(config[depth]);
        aStar.run();
    }
    else if (strcmp(argv[1],"ALL") == 0)
    {
        AStar aStar(config[depth]);
        aStar.run();

        DFS dfs(config[depth]);
        dfs.run();

        IDS ids(config[depth],0);
        ids.run();

        BFS bfs(config[depth]);
        bfs.run();

        std::cout<< "\n";
    }
    else
    {
        std::cerr << "Sorry we haven't implemented that algorithm yet. \n";
    }

}
