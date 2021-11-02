#pragma once
using namespace std;
class Graph
{
	int size;								// ������� ������
	int** matrix_graph;						// ������� �������� ����� (1 � �����, 0 - ���� �����)
	//vector<int*> colors_node;				// ������ ������� ��������� ����� (������(������) ������(������� �������))
	//vector<vector<int>> used_colors;		// ������ ������������ ������� � �������� ���������
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	~Graph();

	void set_element(int row, int column, int elem);					// ���������� ������� � ������� 			
	int get_element(int row, int column);								// �������� ������� � �������
	void set_size(int insize);											// ���������� ������� ������
	int get_size();														// �������� ������� ������

};

