#pragma once
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;
class FileWorker
{
	string filename;
public:
	FileWorker(string name);
	Graph read_graph();
	void write_graph(Graph& graph);
	void write_colors(Graph& graph);
};

