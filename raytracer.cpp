#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>
#include <boost/qvm/vec_operations.hpp>

#include "config.h"

using namespace boost;

using Shape = float;//TODO change
using World = std::vector<std::unique_ptr<Shape>>;
using Color = qvm::vec<float, 3>;
using Vec = qvm::vec<float, 3>;

std::shared_ptr<World> get_world() { // dont really get the point of this function?
    std::shared_ptr<World> world = std::make_shared<World>(World());
    return world;
}

Color trace(const Vec&, const Vec&, std::shared_ptr<World>, const int&);
void render(std::shared_ptr<World>, const Config&);

int main(int argc, char **argv) {
    qvm::vec<float,3> v{0, 0, 1}; // is there a reason why you didnt use Vec here?
    qvm::A<1>(v) += 1; // what does this line do?
    return 0;
}

Color trace(
    const Vec &rayorig,
    const Vec &raydir,
    std::shared_ptr<World> world,
    const int &depth
) {
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
