#ifndef CONFIG_H
#define CONFIG_H

class Config {
public:
    unsigned width;
    unsigned height;
    float fov;

    float invWidth, invHeight;
    float aspectRatio;
    float angle;

    std::string fname;

    Config(unsigned _width, unsigned _height, float _fov) {
        width = _width;
        height = _height;
        fov = _fov;

        invWidth = 1 / float(width); invHeight = 1 / float(height);
        aspectRatio = width / float(height);
        angle = tan(M_PI * 0.5 * fov / 180.);

        fname = "./untitled.ppm";
    }
};

#endif
