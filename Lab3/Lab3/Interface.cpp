#include "Interface.h"


void Interface::console_interface()
{
	int how;
	cout << "Input(1- read graph file, 2 - random graph): " ;
	cin >> how;

	string name;
	cout << "Input name file: ";
	cin >> name;
	name = "file\\" + name;
	FileWorker file(name);
	int bee_worker;
	int bee_scout;
	int count_area;
	

	if (how == 1)
	{
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

			if (((count_iter - 1) % step) == 0)
			{
				cout << "_____________________________________________" << endl;
				cout << "Iteration¹ " << count_iter - 1 << endl;
				write_areas(algo);
				write_used_colors(algo);
				cout << "----------------------------------------------" << endl;
			}
		}

		//file.write_graph(graph);
		//file.write_bee(bee_worker, bee_scout, count_area);
	}
	else
	{
		int size;
		int min_adj;
		int max_adj;
		cout << "Input size graph: ";
		cin >> size;
		cout << "Input min count edje vertises's: ";
		cin >> min_adj;
		cout << "Input max count edje vertises's: ";
		cin >> max_adj;

		
		Graph graph(size);
		graph.generation(min_adj, max_adj);
		
		/*
		bool correct = graph.check_correct_symetric();
		if (correct)
			cout << "symetric true" << endl;
		else
			cout << "symetric false" << endl;
		correct = graph.check_correct_num_edge(min_adj, max_adj);
		if (correct)
			cout << "count true" << endl;
		else
			cout << "count false" << endl;
		cout << "avarage: " << graph.count_avarege_edge() << endl;
		*/

		//write_graph(graph);

		
		cout << "Input count bee worker: ";
		cin >> bee_worker;
		cout << "Input count bee scout:";
		cin >> bee_scout;
		cout << "Input count start area:";
		cin >> count_area;
		
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

			if (((count_iter - 1) % step) == 0)
			{
				cout << "_____________________________________________" << endl;
				cout << "Iteration¹ " << count_iter - 1 << endl;
				write_areas(algo);
				write_used_colors(algo);
				cout << "----------------------------------------------" << endl;
			}
		}

		file.write_graph(graph);
		file.write_bee(bee_worker, bee_scout, count_area);
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
