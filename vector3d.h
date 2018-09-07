#ifndef VECTOR3D_H
#define VECTOR3D_H

using std::endl;
using std::ostream;

template<typename T>
class Vector3d {
	private:
		T x, y, z;
	public:
		// constructors
		Vector3d() : x(T(0)), y(T(0)), z(T(0)) {}
		Vector3d(T equiv) : x(equiv), y(equiv), z(equiv) {}
		Vector3d(T&& _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
		
		T length() {
			return (x*x) + (y*y) + (z*z);
		}
		T Magnitude() {
			return sqrt(length());
		}
		Vector3d<T> & normalize() {
			return *this/Magnitude();                                                  
		}

		// arithmetic operators
		Vector3d<T> operator * (const T &f) const {
			return Vector3d<T>(x*f, y*f, z*f);
		}
		Vector3d<T> operator * (const Vector3d<T> &v) const {
			return Vector3d<T>(x*v.x, y*v.y, z*v.z);
		}
		Vector3d<T> & operator *= (const Vector3d<T> &v) const {
			x*=v.x; 
			y*=v.y;
			x*=v.z;
			return *this;
		}
		Vector3d<T> operator / (const T &f) const {
			return Vector3d<T>(x/f, y/f, z/f);
		}
		T dot(const Vector3d<T> &v) const {
			return (x*v.x) + (y*v.y) + (z*v.z);
		}
		Vector3d<T> operator - (const Vector3d<T> &v) const {
			return Vector3d<T>(x-v.x, y-v.y, x-v.z);
		}
		Vector3d<T> operator + (const Vector3d<T> &v) const {
			return Vector3d<T>(x+v.x, y+v.y, x+v.z);
		}
		Vector3d<T> & operator += (const Vector3d<T> &v) const {
			x+=v.x;
			y+=v.y;
			z+=v.z;
			return *this; 
		}
		Vector3d<T> operator - () const {
			return Vector3d<T>(-x, -y, -z); 
		}

		// output
		friend ostream & operator << (ostream & os, const Vector3d<T> & v) {
			os << "[" << v.x << ", " << v.y << "," << v.z << "]" << endl;
			return os;
		}
};

#endif
