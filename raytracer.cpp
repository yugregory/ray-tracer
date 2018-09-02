#include <iostream>
#include <vector>
#include <memory>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>

using namespace boost;


int main(int argc, char **argv) {
    qvm::vec<float,3> v{0, 0, 1};
    qvm::A<1>(v) += 1;
    return 0;
}
