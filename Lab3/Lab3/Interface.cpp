#include "Interface.h"

void Interface::console_interface()
{
	FileWorker file("graph.txt");
	Graph graph = file.read_graph();

	write_graph(graph);
	file.write_graph(graph);
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
