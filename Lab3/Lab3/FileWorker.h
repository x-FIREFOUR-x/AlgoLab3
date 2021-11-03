#pragma once
#include <string>
#include <fstream>
#include "Graph.h"
#include "Algorithm.h"
using namespace std;
class FileWorker
{
	string filename;			// ��'� �����
public:
	FileWorker(string name);
	Graph read_graph(int& bee_worker, int& bee_scout, int& count_area);			// ������� ���� � ����
	void write_graph(Graph& graph);								// �������� ���� � ����
	void write_colors(Graph& graph, Algorithm& algo);			// �������� ������� ��������� ����� � ����
	void write_used_colors(Graph& graph, Algorithm& algo);		// �������� ����������� ������� ������� ��������� � ����
	void write_bee(int bee_worker, int bee_scout, int count_area);				// �������� ������� ���� � ����
};

