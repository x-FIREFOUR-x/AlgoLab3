#pragma once
#include "Graph.h"
#include "FileWorker.h"

using namespace std;
class Algorithm
{

public:
	void greedy_coloring(Graph& graph, int start_node);			// ������ ��������� �����
	void generation_area(Graph& graph);							// ��������� ������
};

