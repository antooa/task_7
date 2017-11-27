#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class route
{
private:
	string initial;
	string last;
	int stops;
	double length;
public:
	route(): initial(""), last(""), stops(0), length(0){}
	route(string init, string last, int st, double path )
	{
		initial = init;
		this->last = last;
		stops = st;
		length = path;
	}
	friend ifstream& operator >> (ifstream& in, route& r)
	{
		in >> r.initial >> r.last >> r.stops >> r.length;
		return in;
	}
	friend ofstream& operator << (ofstream& out, route& r)
	{
		out << r.initial << " " << r.last << " " <<  r.stops << " " << r.length;
		return out;
	}
	friend ostream& operator << (ostream& out, route& r)
	{
		out << r.initial << " " << r.last << " " << r.stops << " " << r.length << endl;
		return out;
	}
	double mean_lenght();
	string get_init();
	double get_legth();
	int get_stops();
	~route();
};


