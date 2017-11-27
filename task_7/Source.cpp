#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include "route.h"
using namespace std;
template<class T>
T ask(string request)
{
	cout << request << " :";
	T answer;
	cin >> answer;
	return answer;
}
void show_tight(vector<route> &vec)
{
	double limit = ask<double>("Enter the max density of the routes");
	vector<route> demo(vec.size());
	copy_if(vec.begin(), vec.end(), demo.begin(),
		[limit] (route &r)
	{
		double mean = r.mean_lenght();
		return mean < limit;
	});

	for (route &r : demo)
	{
		cout << r;
	}
}

bool length_comp(route &r1, route &r2)
{
	return r1.get_legth() < r2.get_legth();
}
int main()
{
	route pusher;
	ifstream in("Text.txt");
	vector<route> traffic;
	while (!in.fail())
	{
		in >> pusher;
		traffic.push_back(pusher);

	}
	for (route &r : traffic)
	{
		cout << r;
	}
	sort(traffic.begin(), traffic.end(), length_comp);
	show_tight(traffic);
	string X_stop = ask<string>("Enter the name of the initial station");
	vector<route> routes;
	remove_copy_if(traffic.begin(), traffic.end(), routes.begin(),
		[&X_stop](route& rt)
	{
		return rt.get_init() != X_stop;
	});
	for (route &r : routes)
	{
		cout << r;
	}


	_getch();
	return 0;
}