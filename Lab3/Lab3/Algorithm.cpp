#include "Algorithm.h"

void Algorithm::greedy_coloring(Graph& graph)
{
	//graph.set_color(0, 1);
	graph.add_variant_painting();
	int number = graph.get_size_colors_node() - 1;

	bool* available = new bool[graph.get_size()];
	for (int i = 0; i < graph.get_size(); i++)
	{
		available[i] = true;		// ������� ������� ��� ���� �������
	}

	for (int u = 0; u < graph.get_size(); u++)		// ��������� �� ��� �������� ��� ����� 
	{

				// �������� ������� ������� ��� ������� u
		for (int i = 0; i < graph.get_size(); i++)		// ��������� ������� ������ � �������� u
		{
			if (graph.get_element(u, i) == 1)		// ��������� �� ������� u ������ � ��� i
			{
				if (graph.get_color(number, i) != 0)	// ��������� �� ���� �� ���������
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
			}
		}

			// ������ �� ������� ������� ��� �������� �������� �����
		for (int i = 0; i < graph.get_size(); i++)
		{
			available[i] = true;
		}
	}
}
