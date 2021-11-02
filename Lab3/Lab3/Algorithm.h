#pragma once
#include "Graph.h"
#include <vector>

using namespace std;
class Algorithm
{
private:
	int bee_worker;
	int bee_scout;
	vector<vector<int>> areas;				// список варіантів розкраски графа (вектор(варіант) масивів(кольори вершини))
	vector<vector<int>> used_colors;		// список використаних кольорів в варіантах розкраски

public:
	Algorithm(int w, int s);
	void greedy_coloring(Graph& graph, int start_node);			// жадібна розкраска графа (одна ділянка)
	void generation_area(Graph& graph);							// генерація ділянок
	void bee_colony(Graph& graph);								// класичний алгоритм бджолиної колонії розфарбування графа

	int get_count_areas();									// кількість ділянок
	vector<int> get_area(int number_area);					// ділянка
	vector<int> get_used_color(int number_area);			// палітра ділянки
private:
	void add_variant_painting(int size);				// добавити новий варіант розфарбування (нова ділянка)
	void check_new_variant(int size);					// збереження унікальності варіантів розфарбування графа (видалити ділянку якщо така вже існує)

	void add_new_color(int color);							// добавити новий колір до палітри використаних кольорів
	void del_used_color(int number_variant, int color);		// видалити колір з використаних кольорів варіанта номер
};

