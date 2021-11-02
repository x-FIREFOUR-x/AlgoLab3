#include "Algorithm.h"

Algorithm::Algorithm(int w, int s)
{
	bee_worker = w;
	bee_scout = s;
}

void Algorithm::greedy_coloring(Graph& graph, int start_node)
{
	//graph.set_color(0, 1);
	graph.add_variant_painting();
	int number = graph.get_size_colors_node() - 1;

	bool* available = new bool[graph.get_size()];
	for (int i = 0; i < graph.get_size(); i++)
	{
		available[i] = true;		// ������� ������� ��� ���� �������
	}

	int u = start_node;
	do
	{
		// �������� ������� ������� ��� ������� u
		for (int i = 0; i < graph.get_size(); i++)		// ��������� ������� ������ � �������� u
		{
			if (graph.get_element(u, i) == 1)		// ��������� �� ������� u ������ � ��� i
			{
				if (graph.get_color(number, i) != -1)	// ��������� �� ���� �� ���������
				{
					available[graph.get_color(number, i)] = false;		// ���� ������ ������� ����������� �� ��� ���� ����������� ��� ���� �������
				}
			}
		}

		// ��������� ������ ��������� ���� � ������� ������� ������� u
		for (int i = 0; i < graph.get_size(); i++)
		{
			if (available[i] == true)
			{
				graph.set_color(number, u, i);
				graph.add_new_color(i);
				break;
			}
		}

		// ������ �� ������� ������� ��� �������� �������� �����
		for (int i = 0; i < graph.get_size(); i++)
		{
			available[i] = true;
		}

		u++;

		if (u > graph.get_size() - 1)
		{
			u = 0;
		}

	} while (u != start_node);

	graph.check_new_variant();
}

void Algorithm::generation_area(Graph& graph)
{
	for (int i = 0; i < graph.get_size(); i++)
	{
		greedy_coloring(graph, i);
	}
	
}

void Algorithm::bee_colony(Graph& graph)
{
	generation_area(graph);
}
