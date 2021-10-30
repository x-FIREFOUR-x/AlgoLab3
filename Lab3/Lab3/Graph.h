#pragma once
class Graph
{
	int size;
	int** matrix_graph;
	int* colors_node;
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	~Graph();

	void set_element(int row, int column, int elem);
	int get_element(int row, int column);
	void set_size(int insize);
	int get_size();
	void set_color(int number, int color);
	int get_color(int number);
};

