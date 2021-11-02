#pragma once
#include "Graph.h"
#include "FileWorker.h"

using namespace std;
class Algorithm
{
private:
	int bee_worker;
	int bee_scout;
public:
	Algorithm(int w, int s);
	void greedy_coloring(Graph& graph, int start_node);			// жадібна розкраска графа
	void generation_area(Graph& graph);							// генерація ділянок
	void bee_colony(Graph& graph);
};

