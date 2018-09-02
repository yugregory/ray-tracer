#include <iostream>
#include <vector>
#include <memory>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>

using namespace boost;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::vector;

using Shape = float;//TODO change
using World = vector<unique_ptr<Shape>>;
using Color = qvm::vec<float, 3>;
using Vec = qvm::vec<float, 3>;

class Config {
public:
    unsigned width;
    unsigned height;
    float fov;
};

shared_ptr<World> get_world() {
    shared_ptr<World> world = make_shared<World>(World());
    return world;
}

Color trace(
    const Vec &rayorig,
    const Vec &raydir,
    shared_ptr<World> world,
    const int &depth
) {
    return {0, 0, 0};
}

void render(shared_ptr<World> world, const Config config) {
}

int main(int argc, char **argv) {
    qvm::vec<float,3> v{0, 0, 1};
    qvm::A<1>(v) += 1;
    return 0;
}
