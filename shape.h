#ifndef SHAPE_H
#define SHAPE_H

#include "vector3d.h"

using Vector3df = Vector3d<float>;

class Shape {
	private:
		Vector3df surfaceColor;
		Vector3df emissionColor;
	protected:
		float transparency;
		float reflection;
	public:
		Shape(
				const Vector3df &_surfaceColor,
				const Vector3df &_emissionColor,
				const float &_transparency,
				const float &_reflection
			) : surfaceColor(_surfaceColor), emissionColor(_emissionColor), 
				transparency(_transparency), reflection(_reflection) 
		{}
		virtual bool intersect(
				const Vector3df &rayOrig,
				const Vector3df &rayDir,
				float &t0,
				float &t1) const = 0;
};

#endif
