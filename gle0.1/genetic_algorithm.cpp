#include "StdAfx.h"
#include "genetic_algorithm.h"


genetic_algorithm::genetic_algorithm(void)
{
}

void genetic_algorithm::step()
{
	vector<vector<int>> population;
//	evaluate();
//	population = selection();
//	population = reproduction();
	//evaluate(

}

void genetic_algorithm::run()
{
	generate();
	while (!terminate())
	{
		step();
	}
}

void genetic_algorithm::generate()
{
	_time = 0;
//	_population.generate();
	_fit = evaluate(_population);
}

vector<int> genetic_algorithm::evaluate(vector<vector<int>> population)
{
	vector<int> fit;
	for (int i = 0; i < population.size(); i++)
	{
		fit.push_back(fitness(population[i]));
	}
	return fit;
}
