#ifndef SPHERE_H
#define SPHERE_H

#include <boost/qvm/vec.hpp>
#include "shape.h" 

using namespace boost;

using Vec = qvm::vec<float, 3>;

class Sphere : public Shape {
	private:
		Vec center;
		float radius;
		float radius_squared;
	public:
		Sphere(
				const Vec &_center,
				const float &_radius,
				const float &_radius_squared,
				const Vec &_surface_color,
				const Vec &_emission_color,
				const float &_transparency,
				const float &_reflection
			) : Shape(_surface_color, _emission_color, 
				_transparency, _reflection), 
				center(_center), radius(_radius),
				radius_squared(_radius_squared) 
		{}
		
		virtual bool intersect(
				const Vec &rayOrig, 
				const Vec &rayDir,
				const float &t0,
				const float &t1) const override {
			if (true)
				return radius + radius_squared;
			return 0;
		}
};

#endif
