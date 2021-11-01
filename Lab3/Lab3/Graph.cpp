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

	/*colors_node = new int [size];
	for (int i = 0; i < size; i++)
	{
		colors_node[i] = 0;
	}*/
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

	for (int i = 0; i < obj.colors_node.size(); i++)
	{
		int* buf = new int[size];
		colors_node.push_back(buf);
		for (int j = 0; j < size; j++)
		{
			colors_node[i][j] = obj.colors_node[i][j];
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

void Graph::set_color(int number_variant, int number_node, int color)
{
	colors_node[number_variant][number_node] = color;
}

int Graph::get_color(int number_variant , int number_node)
{
	return colors_node[number_variant][number_node];
}

void Graph::add_variant_painting()
{
	int* buf = new int[size];
	colors_node.push_back(buf);
	for (int j = 0; j < size; j++)
	{
		colors_node[colors_node.size() - 1][j] = -1;
	}
}

int Graph::get_size_colors_node()
{
	return colors_node.size();
}

