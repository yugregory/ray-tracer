#ifndef SHAPE_H
#define SHAPE_H

#include <boost/qvm/vec.hpp>

using namespace boost;

using Vec = qvm::vec<float, 3>;

class Shape {
    protected:
        Vec surfaceColor;
        Vec emissionColor;
        float transparency;
        float reflection;
    public:
        Shape(
                const Vec &_surfaceColor,
                const Vec &_emissionColor,
                const float &_transparency,
                const float &_reflection
            ) : surfaceColor(_surfaceColor), emissionColor(_emissionColor), 
                transparency(_transparency), reflection(_reflection) 
        {}

        virtual bool intersect(
                const Vec &rayOrig,
                const Vec &rayDir,
                float &t0,
                float &t1) const = 0;

        virtual ~Shape() = default;
};

#endif
