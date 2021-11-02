#include "FileWorker.h"

FileWorker::FileWorker(string name)
{
	filename = name;
}

Graph FileWorker::read_graph(int& bee_worker, int& bee_scout)
{
	ifstream fin;
	fin.open(filename);
	int size;
	fin >> size;
	Graph graph(size);

	int element;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fin >> element;
			graph.set_element(i, j, element);
		}

	}
	fin >> bee_worker;
	fin >> bee_scout;
	fin.close();

	return graph;
}

void FileWorker::write_graph(Graph& graph)
{
	ofstream fout;
	fout.open(filename);
	fout << graph.get_size() << "\n";
	for (int i = 0; i < graph.get_size(); i++)
	{
		for (int j = 0; j < graph.get_size(); j++)
		{
			fout << graph.get_element(i, j) << " ";
		}
		fout << "\n";
	}
	fout.close();
}

void FileWorker::write_colors(Graph& graph, Algorithm& algo)
{
	ofstream fout;
	fout.open(filename, ios::out|ios::app);
	fout << "Colors: " << "\n";
	
	vector<int> area;
	for (int i = 0; i < algo.get_count_areas(); i++)
	{
		area = algo.get_area(i);
		for (int j = 0; j < area.size(); j++)
		{
			fout << area[j] << " ";
		}
		fout << "\n";
	}
	
	fout.close();
}

void FileWorker::write_used_colors(Graph& graph, Algorithm& algo)
{
	ofstream fout;
	fout.open(filename, ios::out | ios::app);
	fout << "Used colors: " << "\n";

	vector<int> used_color;
	for (int i = 0; i < algo.get_count_areas(); i++)
	{
		used_color = algo.get_used_color(i);
		for (int j = 0; j < used_color.size(); j++)
		{
			fout << used_color[j] << " ";
		}
		fout << "\n";
	}
	

	fout.close();
}

void FileWorker::write_bee(int bee_worker, int bee_scout)
{
	ofstream fout;
	fout.open(filename, ios::out | ios::app);

	fout << bee_worker << " " << bee_scout << "\n";

	fout.close();
}
