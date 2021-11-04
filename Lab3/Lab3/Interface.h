#pragma once
#include <iostream>
#include "FileWorker.h"
#include "Algorithm.h"
using namespace std;
class Interface
{
public:
	void console_interface();				// консольний інтерфейс програми
private:
	void write_graph(Graph graph);				// вивести граф на екран
	void write_areas(Algorithm algo);			// вивести участки
	void write_used_colors(Algorithm algo);		// вивести палітри участків
};

