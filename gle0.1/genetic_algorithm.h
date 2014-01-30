#pragma once

#include <vector>

using namespace std;

class genetic_algorithm
{
public:
	genetic_algorithm(void);

	void generate();
	bool terminate();
//	void evaluate();
	vector<int> evaluate(vector<vector<int>> population);
	void selection();
	void recombination();
	void crossover();
	void mutation();
	void replace(vector<vector<int>> population);

	void step();
	void run();

	vector<int> result();

private:
	vector<vector<int>> _population; 
	int _time;
	vector<int> _fit;
	double fitness(vector<int> member);
};

