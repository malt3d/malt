//
// Created by fatih on 4/27/17.
//

#ifndef MALT_OVERALL_TEST_HPP
#define MALT_OVERALL_TEST_HPP

#include <malt/component.hpp>

class test_component : public malt::component
{
public:
    void Handle(int);
};

#endif //MALT_OVERALL_TEST_HPP
