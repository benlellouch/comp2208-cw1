
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
do 
	./out ASTAR $i >> Astar.csv
	./out BFS $i >> BFS.csv
   	./out DFS $i >> DFS.csv
	./out IDS $i >> IDS.csv	
done

