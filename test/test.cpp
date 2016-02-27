//#include <iostream>
#include <gmock/gmock.h>
#include <complex.h>
#include <iostream>

class TestComplex : public ::testing::Test{
protected:
	void SetUp(){

	}

	void TearDown(){

	}

	ComplexDicart a;
	ComplexDicart b;
	//ComplexPolar c;
	//ComplexPolar d;
};

TEST_F(TestComplex, decart_constructor){
	a = ComplexDicart();
	ASSERT_EQ(a.real(), 0.0);
	ASSERT_EQ(a.imaginary(), 0.0);
}

TEST_F(TestComplex, polar_constructor){
	// c = ComplexPolar();
	// ASSERT_EQ(c.real(), 0.0);
	// ASSERT_EQ(c.imaginary(), 0.0);
	ASSERT_EQ(1, 1);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}