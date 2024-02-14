#include <iostream>

#include "Builder.h"
#include "Groovy.h"
#include "PrototypeFactory.h"
#include "compositebuilder.h"
#include "AbstractFactory.h"
#include "Factory.h"
#include "CopyConstructionPrototype.h"
#include "ClassicSingelton.h"
#include "Adapter.h"
#include "ArrayBackedProperties.h"
#include "GroupObject.h"
#include "DynamicDecorator.h"
#include "StaticDecorator.h"


int main(int argc, char *argv[])
{

/**
 * Builder
 */
std::cout << "\n|===========> Builder <===========|\n";

    auto b = Builder::stringElement::build()->add("hi")->add("bye");
    for(const auto& str : b->stringList)
    {
        std::cout << str.text << '\n';
    }


/**
 * Groovy Builder
 */
std::cout << "\n|===========> Groovy Builder <===========|\n";

    std::cout<<GroovyBuilder::A{
                 GroovyBuilder::C{{"hello world",
                    "this is Groovy Builder"}},
                 GroovyBuilder::C{{"bye world"}}
                };


/**
 * composite builder
 */
std::cout << "\n|===========> Composite Builder <===========|\n";

    CompositeBuilder::PersonBuilder p{};
    CompositeBuilder::Person person = p.lives().at("tehran").in("iran").
                                        work().at("company").as("software");
    std::cout << person << '\n';

/**
 * Factory
 */
std::cout << "\n|===========> Factory <===========|\n";

    auto point = Factory::PointFactory::newCartesian(2.0,3.5);
    point.print();


/**
 * Abstract Factory
 */
std::cout << "\n|===========> Abstract Factory <===========|\n";

    AbstractFactory::WalkFactory f;
    auto walker = f.newWalking(AbstractFactory::WalkFactory::walkMode::Fast);
    walker->startWalking();

/**
 * Copy Construction Prototype
 */
std::cout << "\n|===========> Copy Construction Prototype <===========|\n";

    CopyConstructionPrototype::Contact prototype("",CopyConstructionPrototype::Address{"tehran", "iran"});
    CopyConstructionPrototype::Contact newContact(prototype);
    newContact.name = "ali";
    std::cout << "name:" << newContact.name <<
               "\nAddress: " << newContact.address->city << " " << newContact.address->country << '\n';

/**
 * Prototype Factory
 */
std::cout << "\n|===========> Prototype Factory <===========|\n";

    auto newpContact = PrototypeFactory::Contact::ContactFactory::newTehranContact("ali");
    std::cout << "name:" << newpContact.name <<
                 "\nAddress: " << newpContact.address->city << " " << newpContact.address->country << '\n';

/**
 * Classic Singleton
 */
std::cout << "\n|===========> Classic Singleton <===========|\n";

    auto data = ClassicSingleton::Data::get();
    data->data = 5;
    std::cout << data->data <<'\n';
    auto anotherData = ClassicSingleton::Data::get();
    std::cout << anotherData->data <<'\n';

/**
 * Adapter
 */
std::cout << "\n|===========> Adapter <===========|\n";

    Adapter::Line line(Adapter::Point(0,0),Adapter::Point(3,0));
    Adapter::LineToPointAdapter ltp(line);
    for(const auto& point : ltp.points)
    {
        std::cout << point.x << "," << point.y << '\n';
    }

/**
 * Array Backed
 */
std::cout << "\n|===========> Array Backed <===========|\n";

    ArrayBacked::Score score;
    score.setProperty(20,ArrayBacked::Score::lesson1).
          setProperty(10,ArrayBacked::Score::lesson2).
          setProperty(18,ArrayBacked::Score::lesson3);
    std::cout << score.sum() << '\n';

/**
 * Group Object
 */
std::cout << "\n|===========> Group Object <===========|\n";

    GroupObject::Name ga("a"), gb("b"), gc("c"), gd("d");
    GroupObject::NameGroup group1, group2;
    group1.add(&ga).add(&gb);
    group2.add(&gc).add(&gd).add(&group1);
    group2.print();

/**
 * Dynamic Decorator
 */
std::cout << "\n|===========> Dynamic Decorator <===========|\n";

    DynamicDecorator::Circle circle(3.0F);
    DynamicDecorator::ColoredShape cs(circle, "green");
    DynamicDecorator::TransparentShape ts(cs, 20);
    ts.print();

/**
 * Static Decorator
 */
std::cout << "\n|===========> Static Decorator <===========|\n";

    StaticDecorator::ColoredShape<StaticDecorator::TransparentShape<StaticDecorator::Circle>> cs1("red");
    cs1.transparency = 30;
    cs1.resize(60.0F);
    cs1.print();
    StaticDecorator::ColoredShape<StaticDecorator::TransparentShape<StaticDecorator::Circle>> cs2("green", 20, 50);
    cs2.print();



std::cout << "\n\n|===========> END <===========|\n";

    return 0;
}
