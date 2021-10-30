#pragma once
#include <iostream>
#include "FileWorker.h"
#include "Algorithm.h"
using namespace std;
class Interface
{
public:
	void console_interface();
private:
	void write_graph(Graph graph);
};

