#pragma once
#include <vector>
using namespace std;
class Graph
{
	int size;								// ������� ������
	int** matrix_graph;						// ������� �������� ����� (1 � �����, 0 - ���� �����)
	vector<int*> colors_node;				// ������ ������� ��������� ����� (������(������) ������(������� �������))
	vector<vector<int>> used_colors;		// ������ ������������ ������� � �������� ���������
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	~Graph();

	void set_element(int row, int column, int elem);					// ���������� ������� � ������� 			
	int get_element(int row, int column);								// �������� ������� � �������
	void set_size(int insize);											// ���������� ������� ������
	int get_size();														// �������� ������� ������

	void set_color(int number_variant, int number_node, int color);		// ���������� ���� �������
	int get_color(int number_variant, int number_node);					// �������� ���� �������
	int get_size_colors_node();											// �������� ������� �������
	vector<int> get_used_color(int number_variant);						// �������� ������ ������������ ������� � ������

	void add_variant_painting();				// �������� ����� ������ �������������
	void check_new_variant();					// ���������� ���������� ������� ������������� ����� 
	
	void add_new_color(int color);				// �������� ����� ���� �� ������ ������������ �������
	void del_used_color(int number_variant, int color);			// �������� ���� � ������������ ������� ������� �����
};

