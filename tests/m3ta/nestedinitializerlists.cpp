#include <initializer_list>
#include <type_traits>

#include <m3ta/nestedinitializerlists>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void type()
{
    TEST_ASSERT((std::is_same<m3ta::NestedInitializerListsT<T, 0>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::NestedInitializerListsT<T, 1>, std::initializer_list<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::NestedInitializerListsT<T, 2>, std::initializer_list<std::initializer_list<T>>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::NestedInitializerListsT<T, 3>, std::initializer_list<std::initializer_list<std::initializer_list<T>>>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::NestedInitializerListsT<T, 4>, std::initializer_list<std::initializer_list<std::initializer_list<std::initializer_list<T>>>>>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    type<char>();
    type<unsigned char>();
    type<short>();
    type<unsigned short>();
    type<int>();
    type<unsigned int>();
    type<long>();
    type<unsigned long>();
    return 0;
}
