#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <iostream>
#include "../wfc-cpp/include/wfc.hpp"
#include "../wfc-cpp/include/utils.hpp"

using namespace wfc;


int main(){
    srand(1);
    WFC wfc({10,10,1}, {1,1,1});
    wfc.get_constraints().change_rule(1, Directions::UP, 2, false);
    wfc.get_constraints().change_rule(1, Directions::DOWN, 2, false);
    wfc.get_constraints().change_rule(1, Directions::LEFT, 2, false);
    wfc.get_constraints().change_rule(1, Directions::RIGHT, 2, false);
    std::cout << wfc.get_constraints().get() << std::endl; 

    wfc.stepped.connect([](wfc::WFC* ptr, int c, Vec3u cell){
        std::cout << "-------------------------------" << std::get<0>(cell) << " " << std::get<1>(cell) << std::endl;
        wfc::print_array2d(ptr->get_wave());
    });

    wfc.finished.connect([](WFC* ptr){
        print_array2d(ptr->get_result());
    });

    wfc.init();
    wfc.run();
}

