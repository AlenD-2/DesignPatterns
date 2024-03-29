#include "compositebuilder.h"

#include <iostream>

namespace CompositeBuilder {


PersonBuilderBase::~PersonBuilderBase()
{
    std::cout << "dis" << '\n';
    if(addressBuilder != nullptr)
    {
        delete addressBuilder;
    }

    if(jobBuilder != nullptr)
    {
        delete jobBuilder;
    }
}

PersonAddressBuilder& PersonBuilderBase::lives()
{
    if(addressBuilder == nullptr)
        addressBuilder = new PersonAddressBuilder(this);
    return *addressBuilder;
}

PersonJobBuilder &PersonBuilderBase::work()
{
    if(jobBuilder == nullptr)
        jobBuilder = new PersonJobBuilder(this);
    return *jobBuilder;
}


}
