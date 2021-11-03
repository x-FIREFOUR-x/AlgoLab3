#include "Algorithm.h"
#include <numeric>

Algorithm::Algorithm(int w, int s)
{
	bee_worker = w;
	bee_scout = s;
}


void Algorithm::bee_colony(Graph& graph, int& count_iter)
{
	if (count_iter == 0)
		generation_area(graph);
	sort_area();

}

void Algorithm::generation_area(Graph& graph)
{
	for (int i = 0; i < graph.get_size(); i++)
	{
		greedy_coloring(graph, i);
	}

}

void Algorithm::greedy_coloring(Graph& graph, int start_node)
{
	//graph.set_color(0, 1);
	add_variant_painting(graph.get_size());
	int number = areas.size() - 1;

	bool* available = new bool[graph.get_size()];
	for (int i = 0; i < graph.get_size(); i++)
	{
		available[i] = true;		// доступні кольори для даної вершини
	}

	int u = start_node;
	do
	{
		// визначаєм доступні кольори для вершини u
		for (int i = 0; i < graph.get_size(); i++)		// перебираєм вершини суміжна з вершиною u
		{
			if (graph.get_element(u, i) == 1)		// перевіряєм чи вершина u суміжна з цею i
			{
				if (areas[number][i] != -1)	// перевіряєм чи вона не покрашена
				{
					available[areas[number][i]] = false;		// якщо суміжна вершина зафарбована то цей колір недоступний для даної вершини
				}
			}
		}

		// знаходимо перший доступний колір і красимо поточну вершину u
		for (int i = 0; i < graph.get_size(); i++)
		{
			if (available[i] == true)
			{
				areas[number][u] =  i;
				//used_colors[number].push_back(i);
				add_new_color(i);
				break;
			}
		}

		// робимо всі кольори доступні для наступної ітерації циклу
		for (int i = 0; i < graph.get_size(); i++)
		{
			available[i] = true;
		}

		u++;

		if (u > graph.get_size() - 1)
		{
			u = 0;
		}

	} while (u != start_node);

	check_new_variant(graph.get_size());
}

void Algorithm::sort_area()
{
	vector<int> indexs(areas.size());
	iota(indexs.begin(), indexs.end(), 0);
	

	sort(indexs.begin(), indexs.end(), [&](int a, int b) {return used_colors[a] < used_colors[b]; });

	vector<vector<int>> buf = move(areas);
	areas.resize(buf.size());
	for (int i = 0; i < buf.size(); i++)
	{
		areas[i] = move(buf[indexs[i]]);
	}
	sort(used_colors.begin(), used_colors.end(), [](vector<int> a, vector<int> b) { return a.size() < b.size();} );
	
}


 
int Algorithm::get_count_areas()
{
	return areas.size();
}

vector<int> Algorithm::get_area(int number_area)
{
	return areas[number_area];
}

vector<int> Algorithm::get_used_color(int number_area)
{
	return used_colors[number_area];
}

void Algorithm::add_variant_painting(int size)
{
	vector<int> buf;
	areas.push_back(buf);
	for (int j = 0; j < size; j++)
	{
		areas[areas.size() - 1].push_back(-1);
	}
	used_colors.push_back(vector<int>());
}

void Algorithm::check_new_variant(int size)
{
	int number_new = areas.size() - 1;

	for (int i = 0; i < number_new; i++)
	{
		bool uniq = false;
		for (int j = 0; j < size; j++)
		{
			if (areas[i][j] != areas[number_new][j])
			{
				uniq = true;
				break;
			}
		}
		if (!uniq)
		{
			areas.pop_back();
			used_colors.pop_back();
			break;
		}
	}
}

void Algorithm::add_new_color(int color)
{
	int last = used_colors.size() - 1;
	bool new_cl = true;
	for (size_t i = 0; i < used_colors[last].size(); i++)
	{
		if (color == used_colors[last][i])
		{
			new_cl = false;
		}
	}

	if (new_cl)
		used_colors[last].push_back(color);
}

void Algorithm::del_used_color(int number_variant, int color)
{
	int last = used_colors[number_variant].size() - 1;

	int in_need;
	for (int i = 0; i <= last; i++)
	{
		if (used_colors[number_variant][i] == color)
		{
			in_need = i;
			break;
		}
	}

	auto it = used_colors[number_variant].begin() + in_need;

	used_colors[number_variant].erase(it);
}
