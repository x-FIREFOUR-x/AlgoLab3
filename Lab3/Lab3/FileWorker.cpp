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

void FileWorker::write_colors(Graph& graph)
{
	ofstream fout;
	fout.open(filename, ios::out|ios::app);
	fout << "Colors: " << "\n";
	
	for (int i = 0; i < graph.get_size_colors_node(); i++)
	{
		for (int j = 0; j < graph.get_size(); j++)
		{
			fout << graph.get_color(i, j) << " ";
		}
		fout << "\n";
	}
	
	fout.close();
}

void FileWorker::write_used_colors(Graph& graph)
{
	ofstream fout;
	fout.open(filename, ios::out | ios::app);
	fout << "Used colors: " << "\n";

	for (int i = 0; i < graph.get_size_colors_node(); i++)
	{
		vector<int> list = graph.get_used_color(i);
		for (int j = 0; j < list.size(); j++)
		{
			fout << list[j] << " ";
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
