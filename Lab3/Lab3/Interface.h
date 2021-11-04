#pragma once
#include <iostream>
#include "FileWorker.h"
#include "Algorithm.h"
using namespace std;
class Interface
{
public:
	void console_interface();				// ���������� ��������� ��������
private:
	void write_graph(Graph graph);				// ������� ���� �� �����
	void write_areas(Algorithm algo);			// ������� �������
	void write_used_colors(Algorithm algo);		// ������� ������ �������
};

