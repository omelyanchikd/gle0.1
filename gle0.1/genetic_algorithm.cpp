#include "stdafx.h"
#include "genetic_algorithm.h"


genetic_algorithm::genetic_algorithm(void)
{
}

void genetic_algorithm::step()
{
	vector<string> new_population;
	new_population = select(_population, evaluate(_population,  fitness), for_selection);
	new_population = crossover(new_population, probability_crossover);
	new_population = mutation(new_population, probability_mutation, _class);
	_population = replace(_population, new_population, fitness);
}

void genetic_algorithm::run()
{
	_population = generate(_length, _class, _size);
	_time = 0;
	while (_time < 1000)
	{
		step();
		_time++;
	}
}

vector<string> generate(int l, int n, int p)
{
	vector<string> s;
	for (int i = 0; i < p; i++)
	{
		s.push_back("");
		for (int j = 0; j < l; j++)
		{
			int bit = rand() % n;
			s[i].push_back('0'+ bit);
		}

	}
	return s;
}

vector<double> evaluate(vector<string> population, double fitness(vector<vector<double>> data, vector<double> min, vector<double> max, int classes, string s))
{
	vector<double> result;
	for(int i = 0; i < population.size(); i++)
	{
		result.push_back(fitness(data, min, max, classes, population[i]));
	}
	return result;
}

//Rewrite this for roulette wheel selection.

/*int get_random(map<int, offer> good)
{
	vector<double> probabilities;
	for(map<int, offer>::iterator i = good.begin(); i != good.end(); ++i)
	{
		probabilities.push_back(1/(i->second).get_price());
	}
	boost::random::discrete_distribution<> get_rand(probabilities.begin(), probabilities.end());
	return get_rand(random_generator);
}//*/

vector<string> select(vector<string> population, vector<double> fit, int n)
{
	vector<string> result;
	for (int i = 0; i < n; i++)
	{
		int j = rand() % (population.size());
		result.push_back(population[j]);
	}
	return result;
}

string crossover(string a, string b)
{
	int pos = rand() % (a.length());
	return (a.substr(0,pos) + b.substr(pos+1, b.length()));
}

vector<string> crossover(vector<string> population, double probability)
{	
	vector<string> result;
	for (int i = 0; i < population.size(); i++)
	{
		double p = rand()/(double)RAND_MAX;
		if (p > probability)
		{
			for (int j = 0; j < population.size(); j++)
			{
				double q = rand()/(double)RAND_MAX;
				if (q > probability)
				{
					result.push_back(crossover(population[i], population[j]));
					break;
				}
			}			
		}
	}
	return result;
}

string mutation(string a, int n)
{
	int pos = rand() % (a.length());
	int s = rand() % n;
	char c = '0' + s;
	return (a.substr(0,pos - 1) + c + a.substr(pos + 1, a.length()));
}

vector<string> mutation(vector<string> population, double probability, int n)
{
	vector<string> result;
	for (int i = 0; i < population.size(); i++)
	{
		double p = rand()/RAND_MAX;
		if (p > probability)
		{
			result.push_back(mutation(population[i], n));
		}		
	}
	return result;
}

void sort(vector<string> s, double f(string), int first, int last)
{
    int i = first, j = last;
	string x = s[(first + last) / 2]; 
    do 
	{
		while (f(s[i]) < f(x)) 
			i++;
        while (f(s[j]) > f(x)) 
			j--; 
        if (i <= j) 
		{
            if (i < j)
			{
				swap(s[i], s[j]);
			}
            i++;
            j--;
        }
    } 
	while (i <= j);
    if (i < last)
        sort(s, f, i, last);
    if (first < j)
        sort(s, f, first,j);
}

vector<string> replace(vector<string> old_population, vector<string> new_population, double fitness(string))
{
	vector<string> result;
	for (int i = 0; i < old_population.size(); i++)
	{
		result.push_back(old_population[i]);
	}
	for (int i = 0; i < new_population.size(); i++)
	{
		result.push_back(new_population[i]);
	}
	sort(result, fitness, 0, result.size() - 1);
	result.erase(result.begin() + old_population.size() - 1, result.end());
	return result;
}

double fitness(vector<vector<double>> data, vector<double> min, vector<double> max, int classes, string s)
{
	double fit = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (check(data[i], min, max, classes, s))
			fit += 1;
	}
	return -fit;
}

bool check(vector<double> data, vector<double> min, vector<double> max, int classes, string rule)
{
	for (int i = 0; i < rule.length(); i++)
	{
		double left = (rule[i] - 1) * (max[i] - min[i]) / classes;
		double right = rule[i] * (max[i] - min[i]) / classes;
		if ((data[i] < left) || (data[i] >= right))
			return false;
	}
	return true;
}