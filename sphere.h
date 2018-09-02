#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h" 
#include "vector3d.h"

using Vector3df = Vector3d<float>;

class Sphere : public Shape {
	private:
		Vector3df center;
		float radius;
		float radiusSquared;
	public:
		Sphere(
				const Vector3df &_center,
				const float &_radius,
				const float &_radiusSquared,
				const Vector3df &_surfaceColor,
				const Vector3df &_emissionColor,
				const float &_transparency,
				const float &_reflection
			) : Shape(_surfaceColor, _emissionColor, 
				_transparency, _reflection), 
				center(_center), radius(_radius),
				radiusSquared(_radiusSquared) 
		{}
		
		virtual bool intersect(
				const Vector3df &rayOrig, 
				const Vector3df &rayDir,
				float &t0,
				float &t1) const override {
			return transparency+reflection+radius+radiusSquared;
		}
};

#endif
