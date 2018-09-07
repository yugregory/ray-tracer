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
	Sphere object(center, 2, 4, surface_color, emission_color, 10, 10);
	cout << object.intersect(center, surface_color, 10, 20) << endl;
}
