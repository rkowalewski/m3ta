#include <type_traits>

#include <m3ta/integersequence>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void valueTypeIntegral()
{
    TEST_ASSERT((std::is_same<typename m3ta::IntegerSequence<T>::value_type, T>::value), tests::errorMessageForType<T>());
}

template<typename T>
void sizeIntegral()
{
    TEST_ASSERT((m3ta::IntegerSequence<T>::size() == 0), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 1>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 2>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 4>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 9>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 85>::size() == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1>::size() == 2), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2>::size() == 3), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4>::size() == 4), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>::size() == 5), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>::size() == 6), tests::errorMessageForType<T>());
}

template<typename T>
void asArrayIntegral()
{
    TEST_ASSERT((m3ta::IntegerSequence<T>::asArray() == std::array<T, 0>{}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0>::asArray() == std::array<T, 1>{0}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 1>::asArray() == std::array<T, 1>{1}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 2>::asArray() == std::array<T, 1>{2}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 4>::asArray() == std::array<T, 1>{4}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 9>::asArray() == std::array<T, 1>{9}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 85>::asArray() == std::array<T, 1>{85}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1>::asArray() == std::array<T, 2>{0, 1}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2>::asArray() == std::array<T, 3>{0, 1, 2}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4>::asArray() == std::array<T, 4>{0, 1, 2, 4}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>::asArray() == std::array<T, 5>{0, 1, 2, 4, 9}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>::asArray() == std::array<T, 6>{0, 1, 2, 4, 9, 85}), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    valueTypeIntegral<char>();
    valueTypeIntegral<unsigned char>();
    valueTypeIntegral<short>();
    valueTypeIntegral<unsigned short>();
    valueTypeIntegral<int>();
    valueTypeIntegral<unsigned int>();
    valueTypeIntegral<long>();
    valueTypeIntegral<unsigned long>();
    
    sizeIntegral<char>();
    sizeIntegral<unsigned char>();
    sizeIntegral<short>();
    sizeIntegral<unsigned short>();
    sizeIntegral<int>();
    sizeIntegral<unsigned int>();
    sizeIntegral<long>();
    sizeIntegral<unsigned long>();
    
    asArrayIntegral<char>();
    asArrayIntegral<unsigned char>();
    asArrayIntegral<short>();
    asArrayIntegral<unsigned short>();
    asArrayIntegral<int>();
    asArrayIntegral<unsigned int>();
    asArrayIntegral<long>();
    asArrayIntegral<unsigned long>();
    
    return 0;
}
