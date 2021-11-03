#include "Interface.h"


void Interface::console_interface()
{
	string name;
	cout << "Input name file: ";
	cin >> name;
	name = "file\\" + name;
	FileWorker file(name);
	int bee_worker;
	int bee_scout;
	int count_area;
	Graph graph = file.read_graph(bee_worker, bee_scout, count_area);

	int amount_iter;
	int step;
	cout << "Input amount iteration: ";
	cin >> amount_iter;
	cout << "Input step iteration: ";
	cin >> step;

	Algorithm algo(bee_worker, bee_scout, count_area);
	int count_iter = 0;
	
	while (count_iter - 1 != amount_iter)
	{
		algo.bee_colony(graph, count_iter);

		if ( ((count_iter - 1) % step) == 0)
		{
			cout << "_____________________________________________" << endl;
			cout << "Iteration¹ " << count_iter - 1 << endl;
			write_areas(algo);
			write_used_colors(algo);
			cout << "----------------------------------------------" << endl;
		}
	}

	//write_graph(graph);
	/*
	file.write_graph(graph);
	file.write_bee(bee_worker, bee_scout, count_area);
	file.write_colors(graph, algo);
	file.write_used_colors(graph, algo);
	*/
}

void Interface::write_graph(Graph graph)
{
	cout << graph.get_size() << endl;
	for (int i = 0; i < graph.get_size(); i++)
	{
		for (int j = 0; j < graph.get_size(); j++)
		{
			cout << graph.get_element(i, j) << " ";
		}
		cout << endl;
	}
}

void Interface::write_areas(Algorithm algo)
{
	for (int i = 0; i < algo.get_count_areas(); i++)
	{
		vector<int> area = algo.get_area(i);
		for (int j = 0; j < area.size(); j++)
		{
			cout << area[j] << " ";
		}
		cout << endl;
	}
}

void Interface::write_used_colors(Algorithm algo)
{
	for (int i = 0; i < algo.get_count_areas(); i++)
	{
		vector<int> used_colors = algo.get_used_color(i);
		for (int j = 0; j < used_colors.size(); j++)
		{
			cout << used_colors[j] << " ";
		}
		cout << endl;
	}
}
