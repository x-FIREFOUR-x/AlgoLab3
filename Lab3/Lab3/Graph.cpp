#include "Graph.h"

Graph::Graph()
{
}

Graph::Graph(int in_size)
{
	size = in_size;
	matrix_graph = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix_graph[i] = new int[size];
	}
}

Graph::Graph(const Graph& obj)
{
	size = obj.size;
	matrix_graph = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix_graph[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix_graph[i][j] = obj.matrix_graph[i][j];
		}

	}
}

Graph::~Graph()
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix_graph[i];
	}
	delete[] matrix_graph;
}


void Graph::set_element(int row, int column, int elem)
{
	matrix_graph[row][column] = elem;
}

int Graph::get_element(int row, int column)
{
	return matrix_graph[row][column];
}

void Graph::set_size(int insize)
{
	size = insize;
}

int Graph::get_size()
{
	return size;
}

int Graph::count_edge(int number_node)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count += matrix_graph[number_node][i];

	}
	return count;
}

