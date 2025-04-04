#ifndef SPHERE_H
#define SPHERE_H

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>
#include "shape.h" 

using namespace boost;

using Vec = qvm::vec<float, 3>;

class Sphere : public Shape {
    private:
        Vec center;
        float radius_squared;
    public:
        float radius;
    public:
        Sphere(
                const Vec &_center,
                const float &_radius,
                const Vec &_surface_color,
                const float &_reflection = 0,
                const float &_transparency = 0,
                const Vec &_emission_color = {0, 0, 0}
            ) : Shape(_surface_color, _reflection,
                _transparency, _emission_color), 
                center(_center), radius_squared(_radius*_radius),
                radius(_radius)
        {}
        
        virtual bool intersect(
                const Vec &ray_orig, 
                const Vec &ray_dir,
                float &t0,
                float &t1) const override {
            Vec l = center - ray_orig;
            float tca = qvm::dot(l, ray_dir);
            if (tca < 0)
                return false;
            float d2 = qvm::dot(l, l) - (tca * tca);
            if (d2 > radius_squared)
                return false;
            float thc = sqrt(radius_squared - d2);
            t0 = tca - thc;
            t1 = tca + thc;
            return true;
        }

        ~Sphere() = default;
};

#endif
