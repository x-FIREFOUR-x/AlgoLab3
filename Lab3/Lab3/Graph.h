#pragma once
#include <vector>
using namespace std;
class Graph
{
	int size;								// к≥льк≥сть вершин
	int** matrix_graph;						// матриц€ сум≥жност≥ графа (1 Ї ребро, 0 - нема ребра)
	vector<int*> colors_node;				// список вар≥ант≥в розкраски графа (вектор(вар≥ант) масив≥в(кольори вершини))
	vector<vector<int>> used_colors;		// список використаних кольор≥в в вар≥антах розкраски
public:
	Graph();
	Graph(int in_size);
	Graph(const Graph& obj);
	~Graph();

	void set_element(int row, int column, int elem);					// встановити елемент в матрицю 			
	int get_element(int row, int column);								// отримати елемент з матриц≥
	void set_size(int insize);											// встановити к≥льк≥сть вершин
	int get_size();														// отримати к≥льк≥сть вершин

	void set_color(int number_variant, int number_node, int color);		// встановити кол≥р вершини
	int get_color(int number_variant, int number_node);					// отримати кол≥р вершини
	int get_size_colors_node();											// отримати к≥льк≥сть вар≥ант≥в
	vector<int> get_used_color(int number_variant);						// отримати вектор використаних кольор≥в в вар≥ант≥

	void add_variant_painting();				// добавити новий вар≥ант розфарбуванн€
	void check_new_variant();					// збереженн€ ун≥кальност≥ вар≥ант≥в розфарбуванн€ графа 
	
	void add_new_color(int color);				// добавити новий кол≥р до пал≥три використаних кольор≥в
	void del_used_color(int number_variant, int color);			// видалити кол≥р з використаних кольор≥в вар≥анта номер
};

