//#include <iostream>
#include <gmock/gmock.h>
#include <complex.h>
#include <iostream>

class TestComplexDicart : public ::testing::Test{
protected:
	void SetUp(){

	}

	void TearDown(){

	}

	ComplexDicart a;
	ComplexDicart b;
	// ComplexPolar c;
	// ComplexPolar d;
};

TEST_F(TestComplexDicart, dicart_constructor){
	a = ComplexDicart();
	ASSERT_EQ(a.real(), 0.0);
	ASSERT_EQ(a.imaginary(), 0.0);
	a = ComplexDicart(12.8);
	ASSERT_EQ(a.real(), 12.8);
	ASSERT_EQ(a.imaginary(), 0.0);
	a = ComplexDicart(14.3, 25.67);
	ASSERT_EQ(a.real(), 14.3);
	ASSERT_EQ(a.imaginary(), 25.67);
	ComplexDicart t1(a);
	ASSERT_EQ(t1.real(), 14.3);
	ASSERT_EQ(t1.imaginary(), 25.67);
	ComplexDicart t2 = a;
	ASSERT_EQ(t2.real(), 14.3);
	ASSERT_EQ(t2.imaginary(), 25.67);
}

TEST_F(TestComplexDicart, equation){
	a = ComplexDicart(12.1);
	b = ComplexDicart(12.2, 0.1);
	ASSERT_EQ(complex_eq(a, b, 0.3), true);
	ASSERT_EQ(complex_eq(a, b, 0.03), false);
	a = b;
	ASSERT_EQ(a == b, true);
	a = ComplexDicart(12.4, 2452.1);
	ASSERT_EQ(a == b, false);
	ASSERT_EQ(a < b, false);
	b = ComplexDicart(150.2, -12222.2);
	ASSERT_EQ(a < b, true);
}

TEST_F(TestComplexDicart, adding){
	a = ComplexDicart(14.2, 13.2);
	b = ComplexDicart(32.1, 11.4);
	ASSERT_EQ(a + b, ComplexDicart(46.3, 24.6));
	ASSERT_EQ(a + 2.7, ComplexDicart(16.9, 13.2));
	ASSERT_EQ(1.4 + b, ComplexDicart(33.5, 11.4));
	b = ComplexDicart();
	ASSERT_EQ(a + b, a);
}


// TEST_F(TestComplex, polar_constructor){
// 	c = ComplexPolar();
// 	ASSERT_EQ(c.mod(), 0.0);
// 	ASSERT_EQ(c.angle(), 0.0);
// 	c = ComplexPolar(14.0);
// 	ASSERT_EQ(c.mod(), 14.0);
// 	ASSERT_EQ(c.angle(), 0.0);
// 	c = ComplexPolar(23.6, 0.0);
// 	ASSERT_EQ(c.mod(), 23.6);
// 	ASSERT_EQ(c.angle(), 0.0);
// 	c = ComplexPolar(0.0, 24.5);
// 	ASSERT_EQ(c.mod(), 0.0);
// 	ASSERT_EQ(c.angle(), 0.0);
// 	c = ComplexPolar(16.0, 12.1);
// 	ASSERT_EQ(c.mod(), 16.0);
// 	ASSERT_EQ(c.angle(), 12.1);
// 	ComplexPolar t1(c);
// 	ASSERT_EQ(t1.mod(), 16.0);
// 	ASSERT_EQ(t1.angle(), 12.1);
// 	ComplexPolar t2 = c;
// 	ASSERT_EQ(t2.mod(), 16.0);
// 	ASSERT_EQ(t2.angle(), 12.1);
// }

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}