//
// Created by fatih on 4/27/17.
//

#ifndef MALT_OVERALL_TEST_HPP
#define MALT_OVERALL_TEST_HPP

#include <sample/sample_module.hpp>

class test_component : public malt::component
{
public:
    int data = 8;
    void Handle(int);
};

#endif //MALT_OVERALL_TEST_HPP
