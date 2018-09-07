#include <iostream>
#include <boost/qvm/vec.hpp>

#include "sphere.h"

using namespace boost;

using std::cout;
using std::endl;
using Vec = qvm::vec<float, 3>;

void test_sphere();

int main() {
	test_sphere();
	return 0;
}

void test_sphere() {
	Vec center;
	Vec surface_color;
	Vec emission_color;
	Sphere object(center, 2, surface_color, emission_color, 10, 10);
	float temp1 = 10;
	float temp2 = 20;
	cout << object.intersect(center, surface_color, temp1, temp2) << endl;
}
