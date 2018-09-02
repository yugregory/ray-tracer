#ifndef OBJECT_H
#define OBJECT_H

#include "vector3d.h"

using Vector3df = Vector3d<float>;

class Object {
	private:
		Vector3df center;
		Vector3df surfaceColor;
		Vector3df emissionColor;
		float transparency;
		float reflection;
	public:
		Object(
				const Vector3df &_center,
				const Vector3df &_surfaceColor,
				const Vector3df &_emissionColor,
				const float &_transparency,
				const float &_reflection
			) : center(_center), surfaceColor(_surfaceColor),
				emissionColor(_emissionColor), transparency(_transparency),
				reflection(_reflection) 
		{}
		virtual bool intersect(
				const Vector3df &rayOrig,
				const Vector3df &rayDir,
				float &t0,
				float &t1) const {}
};

#endif
