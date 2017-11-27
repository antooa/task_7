#include "route.h"
#include<fstream>




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

int route::get_stops()
{
	return stops;
}

route::~route()
{
}
