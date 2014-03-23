#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

double fitness(vector<vector<double>> data, vector<double> min, vector<double> max, int classes, string s);

bool check(vector<double> data, vector<double> min, vector<double> max, int classes, string rule);

vector<string> generate(int l, int n, int p);

vector<double> evaluate(vector<string> population, double fitness(vector<vector<double>> data, vector<double> min, vector<double> max, int classes, string s));

vector<string> select(vector<string> population, vector<double> fit, int n);

vector<string> crossover(vector<string> population, double probability);

vector<string> mutation(vector<string> population, double probability, int n);

vector<string> replace(vector<string> old_population, vector<string> new_population, double fitness(vector<vector<double>> data, vector<double> min, vector<double> max, int classes, string s));

class genetic_algorithm
{
public:

	genetic_algorithm(void);

	void step();
	void run();

//	string result();

private:

	vector<string> _population; 
	int _time;
//	double fitness(string member);

	int _length;
	int _class;
	int _size;
	
	int for_selection;
	double probability_crossover;
	double probability_mutation;

};

