#include "Algorithm.h"
#include <numeric>
#include <iostream>
struct compair_select_node
{
	bool operator()(pair<pair<int,int>, int> a, pair<pair<int, int>, int> b)
	{
		if (a.first.first < b.first.first)
		{
			return true;
		}
		else
		{
			if (a.first.first > b.first.first)
			{
				return false;
			}
			else
			{
				if (a.first.second < b.first.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
};

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
	
	if (bee_scout <= areas.size())
	{
		for (int i = 0; i < bee_scout - 1; i++)
		{
			sending_worker(graph, i, bee_worker / bee_scout);
		}
		int in_random_area = rand() % (areas.size() - (bee_scout - 1)) + (bee_scout - 1);
		sending_worker(graph, in_random_area, bee_worker / bee_scout);
	}
	else
	{
		for (int i = 0; i < areas.size(); i++)
		{
			sending_worker(graph, i, bee_worker / bee_scout);
			output();
		}
	}
	
	
	count_iter++;
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

	delete[] available;

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

void Algorithm::sending_worker(Graph& graph, int number_area, int count_bee_worker)
{
	priority_queue <pair<pair<int, int>, int>, vector<pair <pair<int, int>, int> >, compair_select_node > pri_que;
	for (int i = 0; i < graph.get_size(); i++)		// кладем всі вершини графа в чергу 
	{
		pair<int, int> parametr(areas[number_area][i], graph.count_edge(i));	// параметри черги колір вершини кількість ребер
		pri_que.push(pair <pair<int, int>, int> (parametr, i));
	}

	/*
	while (!pri_que.empty())
	{
		pair <pair<int, int>, int> k = pri_que.top();
		pri_que.pop();
		cout << number_area << " " << k.second << " " << k.first.first << " " << k.first.second << endl;
	}
	cout << endl;
	*/
	pair<pair<int, int>, int> node;	
	while (count_bee_worker != 0 && !pri_que.empty())			// поки є робочі працюєм на ційй ділянці
	{
		node = pri_que.top();			// вершина з черги
		pri_que.pop();

		vector<int> adjacent_nodes;							// вектор індексів суміжних вершин вершини витягнутої з черги 
		for (int i = 0; i < graph.get_size(); i++)
		{
			if (graph.get_element(node.second,i) != 0)
			{
				adjacent_nodes.push_back(i);
			}
		}

		for (int i = 0; i < node.first.second && count_bee_worker != 0; i++)	// відпрвляєм робочих на сусідні вершини від витягнутої з черги
		{
			swap_nodes(graph, number_area, node.second, adjacent_nodes[i]);
			count_bee_worker--;
		}
	}

}

bool Algorithm::swap_nodes(Graph& graph, int number_area, int num_node, int num_adj_node)
{
	int cl_node = areas[number_area][num_node];					// колір витягнутої з черги вершини
	int cl_adj_node = areas[number_area][num_adj_node];			// колір вершини на яку полетів робочий

	bool imposible_swap = true;
	
	for (int i = 0; i < graph.get_size(); i++)				// перевіряєм чи суміжні вершини num_adj_node не мають кольору cl_node
	{
		if (graph.get_element(num_adj_node, i) != 0 && i != num_node)
		{
			if (areas[number_area][i] == cl_node )
			{
				imposible_swap = false;
				break;
			}
		}
	}

	if (imposible_swap)
	{
		for (int i = 0; i < graph.get_size(); i++)				// перевіряєм чи суміжні вершини num_node не мають кольору cl_adj_node
		{
			if (graph.get_element(num_node, i) != 0 && i != num_adj_node)
			{
				if (areas[number_area][i] == cl_node )
				{
					imposible_swap = false;
					break;
				}
			}
		}
	}

	if (imposible_swap)      // міняєм кольори
	{
		areas[number_area][num_node] = cl_adj_node;					
		areas[number_area][num_adj_node] = cl_node;

		//map<>
		vector<bool> available;
		for (int i = 0; i < used_colors[number_area].size(); i++)
		{
			available.push_back(true);
		}

		for (int i = 0; i < graph.get_size(); i++)			// знаходимо всі кольори сусідніх вершин вершини num_adj_node і робимо їх недоступними
		{
			if (graph.get_element(num_adj_node, i) != 0)
			{
				available[areas[number_area][i]] = false;
			}
		}

		int new_color = cl_node;
		for (int i = 0; i < available.size(); i++)		// находимо перший доступний колір для покраски num_adj_node
		{
			if (available[i] == true)
			{
				new_color = i;
			}
		}

		if (new_color != cl_node)    // перевіряєм чи можемо перекрасити і здихатися від крайнього кольору
		{
			areas[number_area][num_adj_node] = new_color;
			bool cl_node_is = false;
			for (int i = 0; i < graph.get_size(); i++)
			{
				if (areas[number_area][i] == cl_node)
				{
					cl_node_is = true;
					break;
				}
			}

			if (!cl_node_is)
			{
				del_used_color(number_area, cl_node);
				//used_colors[number_area].pop_back();
			}
		}
	}
	

	return imposible_swap;
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

void Algorithm::output()
{
	for (int i = 0; i < areas.size(); i++)
	{

	}
}
