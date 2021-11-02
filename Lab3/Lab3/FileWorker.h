#pragma once
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;
class FileWorker
{
	string filename;			// ім'я файла
public:
	FileWorker(string name);
	Graph read_graph(int& bee_worker, int& bee_scout);						// зчитати граф в файлі
	void write_graph(Graph& graph);			// записати граф в файл
	void write_colors(Graph& graph);		// записати варіанти розкраски графа в файл
	void write_used_colors(Graph& graph);	// записати використанні кольори варіантів розкраски в файл
	void write_bee(int bee_worker, int bee_scout);
};

