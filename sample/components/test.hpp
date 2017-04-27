//
// Created by fatih on 4/27/17.
//

#ifndef MALT_OVERALL_TEST_HPP
#define MALT_OVERALL_TEST_HPP

#include <sample/sample_module.hpp>

struct render{};
class test_component : public sample_module::component_t
{
public:
    int data = 8;
    void Handle(int);
};

#endif //MALT_OVERALL_TEST_HPP
