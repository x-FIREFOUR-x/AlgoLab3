#pragma once
#include <vector>
using namespace std;
class Graph
{
	int size;								// ������� ������
	int** matrix_graph;						// ������� �������� ����� (1 � �����, 0 - ���� �����)
	
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	~Graph();

	void set_element(int row, int column, int elem);					// ���������� ������� � ������� 			
	int get_element(int row, int column);								// �������� ������� � �������
	void set_size(int insize);											// ���������� ������� ������
	int get_size();														// �������� ������� ������
	int count_edge(int number_node);									// ������� ��� �������

	bool generation(int min_adj_edge, int max_adj_edge);				// ��������� ����������� �����
	bool check_correct_symetric();										// �������� ������������ � ���� �� 0 �����
	bool check_correct_num_edge(int min_adj_edge, int max_adj_edge);	// �������� ������� ����� � �����
	int count_avarege_edge();											// ������ �������� ����� � �����
};

