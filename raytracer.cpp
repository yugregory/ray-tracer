#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>
#include <boost/qvm/vec_operations.hpp>

#include "config.h"
#include "sphere.h"

using namespace boost;

using World = std::vector<std::shared_ptr<Sphere>>;
using Color = qvm::vec<float, 3>;
using Vec = qvm::vec<float, 3>;

std::shared_ptr<World> get_world() {
    // TODO dynamically load shapes
    std::shared_ptr<World> world = std::make_shared<World>(World());
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{ 0.0, -10004, -20}, 10000, Vec{0.20, 0.20, 0.20}, 0, 0.0, Vec{0, 0, 0})));
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{ 0.0, 0, -20}, 4, Vec{1.00, 0.32, 0.36}, 1, 0.5, Vec{0, 0, 0})));
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{ 5.0, -1, -15}, 2, Vec{0.90, 0.76, 0.46}, 1, 0.0, Vec{0, 0, 0})));
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{ 5.0, 0, -25}, 3, Vec{0.65, 0.77, 0.97}, 1, 0.0, Vec{0, 0, 0})));
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{-5.5, 0, -15}, 3, Vec{0.90, 0.90, 0.90}, 1, 0.0, Vec{0, 0, 0})));
    // light
    world->push_back(std::make_shared<Sphere>(Sphere(Vec{ 0.0, 20, -30}, 3, Vec{0.00, 0.00, 0.00}, 0, 0.0, Vec{3, 3, 3}))); 
    return world;
}

Color trace(const Vec&, const Vec&, std::shared_ptr<World>, const int&);
void render(std::shared_ptr<World>, const Config&);

int main(int argc, char **argv) {
    auto world = get_world();
    Config config(640, 480, 30);

    render(world, config);
    return 0;
}

Color trace(
    const Vec &rayorig,
    const Vec &raydir,
    std::shared_ptr<World> world,
    const int &depth
) {
    float tnear = INFINITY;
    std::shared_ptr<Sphere> sphere(nullptr);
    for (auto& sph: *world) {
        float t0 = INFINITY, t1 = INFINITY;
        if (sph->intersect(rayorig, raydir, t0, t1)) {
            if (t0 < 0) t0 = t1;
            if (t0 < tnear) {
                tnear = t0;
                sphere = sph;
            }
        } 
    }
    return {0, 0, 0};
}

void render(std::shared_ptr<World> world, const Config& config) {
    auto image = std::make_unique<Color[]>(config.width * config.height);
    for (unsigned y = 0; y < config.height; y++) {
        for (unsigned x = 0; x < config.width; x++) {
            float xx = (2 * ((x + 0.5) * config.invWidth) - 1) * config.angle * config.aspectRatio;
            float yy = (1 - 2 * ((y + 0.5) * config.invHeight)) * config.angle;

            Vec raydir{xx, yy, -1};
            qvm::normalize(raydir);
            image[y * config.height + x] = trace(Vec{0, 0, 0}, raydir, world, 0);
        }
    }
    std::ofstream ofs(config.fname.c_str(), std::ios::out | std::ios::binary);
    ofs << "P6\n" << config.width << " " << config.height << "\n255\n";
    for (unsigned i = 0; i < config.width * config.height; ++i) {
        ofs << (unsigned char)(std::min(float(1), qvm::A<0>(image[i])) * 255) <<
            (unsigned char)(std::min(float(1), qvm::A<1>(image[i])) * 255) <<
            (unsigned char)(std::min(float(1), qvm::A<2>(image[i])) * 255);
    }
    ofs.close(); 
}
