#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <iostream>
#include "../wfc-cpp/include/wfc.hpp"
#include "../wfc-cpp/include/utils.hpp"

using namespace wfc;


int main(){
    srand(1);
    wfc::WFC wfc({10,10,1}, {1,1,1});
    wfc.get_constraints().change_rule(1, wfc::Directions::UP, 2, false);
    std::cout << wfc.get_constraints().get()[0][1].size();
    // wfc.get_constraints().change_rule(1, wfc::Directions::DOWN, 2, false);
    // wfc.get_constraints().change_rule(1, wfc::Directions::LEFT, 2, false);
    // wfc.get_constraints().change_rule(1, wfc::Directions::RIGHT, 2, false);
    std::cout << wfc.get_constraints().get() << std::endl; 

    wfc.stepped.connect([](wfc::WFC* ptr){
        wfc::print_array2d(ptr->get_wave());
        std::cout << "-------------------------------" << std::endl;
    });

    wfc.finished.connect([](wfc::WFC* ptr){
        wfc::print_array2d(ptr->get_result());
    });

    wfc.init();
    wfc::print_array2d(wfc.get_wave());
    auto p = wfc.select_cell();
    wfc.collapse_cell(p.value());
    // wfc.propagate_constraints(p.value());
    wfc::print_array2d(wfc.get_wave());
}

