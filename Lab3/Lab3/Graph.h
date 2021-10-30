#pragma once
class Graph
{
	int size;
	int** matrix_graph;
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	void set_element(int row, int column, int elem);
	int get_element(int row, int column);
	void set_size(int insize);
	int get_size();
	~Graph();
};

