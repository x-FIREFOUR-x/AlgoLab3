#include "Algorithm.h"

void Algorithm::greedy_coloring(Graph& graph)
{
	graph.set_color(0, 1);

	bool* available = new bool[graph.get_size()];
	for (int i = 0; i < graph.get_size(); i++)
	{
		available[i] = true;		// ������� ������� ��� ���� �������
	}

	for (int u = 1; u < graph.get_size(); u++)		// ��������� �� ��� �������� ��� ����� 
	{

				// �������� ������� ������� ��� ������� u
		for (int i = 0; i < graph.get_size(); i++)		// ��������� ������� ������ � �������� u
		{
			if (graph.get_element(u, i) == 1)		// ��������� �� ������� u ������ � ��� i
			{
				if (graph.get_color(i) != 0)	// ��������� �� ���� �� ���������
				{
					available[graph.get_color(i)] = false;		// ���� ������ ������� ����������� �� ��� ���� ����������� ��� ���� �������
				}
			}
		}
		
			// ��������� ������ ��������� ���� � ������� ������� ������� u
		for (int i = 0; i < graph.get_size(); i++)
		{
			if (available[i] == true)
			{
				graph.set_color(u, i);
			}
		}

			// ������ �� ������� ������� ��� �������� �������� �����
		for (int i = 0; i < graph.get_size(); i++)
		{
			available[i] = true;
		}
	}
}
