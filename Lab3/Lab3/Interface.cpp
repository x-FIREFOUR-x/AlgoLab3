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
	Graph graph = file.read_graph(bee_worker, bee_scout);

	Algorithm algo(bee_worker, bee_scout);
	algo.bee_colony(graph);

	//write_graph(graph);
	file.write_graph(graph);
	file.write_bee(bee_worker, bee_scout);
	file.write_colors(graph);
	file.write_used_colors(graph);
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
