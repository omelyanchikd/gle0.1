#pragma once

#include <vector>
#include <string>

using namespace std;

class encode
{

public:

	encode(void);
	bool check(vector<double> data, string rule);

private:

	int _class;
	vector<double> min;
	vector<double> max;
};

