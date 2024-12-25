#include "action.hh"
#include "generator.hh"   ??include this to use MyPrimaryGenerator

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}
void MyActionInitialization::Build() const
{
MyPrimaryGenerator *generator = new MyPrimaryGenerator();
SetUserAction(generator);  // Set the primary generator action

}
