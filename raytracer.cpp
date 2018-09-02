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

class Shape;

using World = vector<unique_ptr<Shape>>;

shared_ptr<World> get_world() {
    shared_ptr<World> world = make_shared<World>(World());
    return world;
}

int main(int argc, char **argv) {
    qvm::vec<float,3> v{0, 0, 1};
    qvm::A<1>(v) += 1;
    return 0;
}
