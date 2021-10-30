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

	colors_node = new int [size];
	for (int i = 0; i < size; i++)
	{
		colors_node[i] = 0;
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

	colors_node = new int[size];
	for (int i = 0; i < size; i++)
	{
		colors_node[i] = obj.colors_node[i];
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

void Graph::set_color(int number, int color)
{
	colors_node[number] = color;
}

int Graph::get_color(int number)
{
	return colors_node[number];
}

