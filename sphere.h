#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h" 
#include "vector3d.h"

using Vector3df = Vector3d<float>;

class Sphere : public Shape {
	private:
		Vector3df center;
		float radius;
		float radius_squared;
	public:
		Sphere(
				const Vector3df &_center,
				const float &_radius,
				const float &_radius_squared,
				const Vector3df &_surface_color,
				const Vector3df &_emission_color,
				const float &_transparency,
				const float &_reflection
			) : Shape(_surface_color, _emission_color, 
				_transparency, _reflection), 
				center(_center), radius(_radius),
				radius_squared(_radius_squared) 
		{}
		
		virtual bool intersect(
				const Vector3df &rayOrig, 
				const Vector3df &rayDir,
				const float &t0,
				const float &t1) const override {
			if (true)
				return radius + radius_squared;
			return 0;
		}
};

#endif
