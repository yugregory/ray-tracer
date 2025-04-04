#ifndef SHAPE_H
#define SHAPE_H


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
                const float &_reflection,
                const float &_transparency,
                const Vec &_emissionColor
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
