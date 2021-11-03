#pragma once
#include "Graph.h"
#include <vector>
#include <algorithm>

using namespace std;
class Algorithm
{
private:
	int bee_worker;
	int bee_scout;
	vector<vector<int>> areas;				// ������ ������� ��������� ����� (������(������) ������(������� �������))
	vector<vector<int>> used_colors;		// ������ ������������ ������� � �������� ���������

public:
	Algorithm(int w, int s);

	void bee_colony(Graph& graph, int& count_iter);				// ��������� �������� �������� ����� ������������� �����

	void generation_area(Graph& graph);							// ��������� ������
	void greedy_coloring(Graph& graph, int start_node);			// ������ ��������� ����� (���� ������)
	
	void sort_area();										// ���������� ������ �� ���������� ������� ������� � �� �����

	int get_count_areas();									// ������� ������
	vector<int> get_area(int number_area);					// ������
	vector<int> get_used_color(int number_area);			// ������ ������
private:
	void add_variant_painting(int size);				// �������� ����� ������ ������������� (���� ������)
	void check_new_variant(int size);					// ���������� ���������� ������� ������������� ����� (�������� ������ ���� ���� ��� ����)

	void add_new_color(int color);							// �������� ����� ���� �� ������ ������������ �������
	void del_used_color(int number_variant, int color);		// �������� ���� � ������������ ������� ������� �����
};

