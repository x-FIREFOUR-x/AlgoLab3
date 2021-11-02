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
	void greedy_coloring(Graph& graph, int start_node);			// ������ ��������� �����
	void generation_area(Graph& graph);							// ��������� ������
	void bee_colony(Graph& graph);
};

