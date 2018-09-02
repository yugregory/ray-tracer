#ifndef VECTOR3D_H
#define VECTOR3D_H

template<typename T>
class Vector3d {
	private:
		T x, y, z;
	public:
		// constructors
		Vector3d() : x(T(0)), y(T(0)), z(T(0)) {}
		Vector3d(T equiv) : x(equiv), y(equiv), z(equiv) {}
		Vector3d(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

		
		Vector3d & normalize() {

		}
}

#endif
