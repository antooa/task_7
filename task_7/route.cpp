#include "route.h"
#include<fstream>



friend ifstream& operator >> (ifstream& in, route& r)
{

}
double route::mean_lenght()
{
	return length / stops;
}

string route::get_init()
{
	return initial;
}

double route::get_legth()
{
	return length;
}

route::~route()
{
}
