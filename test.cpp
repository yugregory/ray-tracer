#include <iostream>

#include "vector3d.h"
#include "sphere.h"

using std::cout;
using std::endl;

void test_sphere();

int main() {
	test_sphere();
	return 0;
}

void test_sphere() {
	const Vector3df center;
	const Vector3df surface_color;
	const Vector3df emission_color;
	Sphere object(center, 2, 4, surface_color, emission_color, 10, 10);
	cout << object.intersect(center, surface_color, 10, 20) << endl;
}
