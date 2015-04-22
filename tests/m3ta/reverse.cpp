#include <type_traits>

#include <m3ta/integersequence>
#include <m3ta/reverse>
#include <m3ta/parameterpack>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeForIntegerSequence()
{
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T, 1, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 2, 1, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 4, 2, 1, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 9, 4, 2, 1, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 85, 9, 4, 2, 1, 0>>::value), tests::errorMessageForType<T>());
}

void typeForParameterPack()
{
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char>>, m3ta::ParameterPack<char>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<short>>, m3ta::ParameterPack<short>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<int>>, m3ta::ParameterPack<int>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<long>>, m3ta::ParameterPack<long>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<float>>, m3ta::ParameterPack<float>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<double>>, m3ta::ParameterPack<double>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<short, char>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<int, short, char>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<long, int, short, char>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<float, long, int, short, char>>::value));
    TEST_ASSERT((std::is_same<m3ta::ReverseT<m3ta::ParameterPack<char, short, int, long, double>>, m3ta::ParameterPack<double, long, int, short, char>>::value));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    typeForIntegerSequence<char>();
    typeForIntegerSequence<unsigned char>();
    typeForIntegerSequence<short>();
    typeForIntegerSequence<unsigned short>();
    typeForIntegerSequence<int>();
    typeForIntegerSequence<unsigned int>();
    typeForIntegerSequence<long>();
    typeForIntegerSequence<unsigned long>();
    
    typeForParameterPack();
    
    return 0;
}
