#include "StdAfx.h"
#include "encode.h"


encode::encode(void)
{
}

bool encode::check(vector<double> data, string rule)
{
	for (int i = 0; i < rule.length(); i++)
	{
		double left = (rule[i] - 1) * (max[i] - min[i]) / _class;
		double right = rule[i] * (max[i] - min[i]) / _class;
		if ((data[i] < left) || (data[i] >= right))
			return false;
	}
	return true;
}
