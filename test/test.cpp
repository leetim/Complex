//#include <iostream>
#include <gmock/gmock.h>
#include <complex.h>
#include <iostream>
#include <cmath>

using namespace std;

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
	a = ComplexPolar(12, 0.3);
	ASSERT_NEAR(a.real(), 11.464037869507, 0.00000001);
	ASSERT_NEAR(a.imaginary(), 3.5462424799, 0.00000001);

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
	ASSERT_EQ(a < ComplexDicart(12.4), false);
	ASSERT_EQ(b < ComplexDicart(150.2), true);
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

TEST_F(TestComplexDicart, difference){
	a = ComplexDicart(14.2, 13.2);
	b = ComplexDicart(32.1, 11.4);
	ASSERT_EQ(a - b, ComplexDicart(-17.9, 1.8));
	ASSERT_EQ(a - 13.2, ComplexDicart(1.0, 13.2));
	ASSERT_EQ(30.0 - b, ComplexDicart(-2.1, -11.4));
	b = ComplexDicart();
	ASSERT_EQ(a - b, a);
	ASSERT_EQ(b - a, -a);
}

TEST_F(TestComplexDicart, multiple){
	a = ComplexDicart(14.2, 13.2);
	b = ComplexDicart(32.1, 11.4);
	ASSERT_EQ(a * b, ComplexDicart(305.34, 585.6));
	ASSERT_EQ(a * 2.5, ComplexDicart(35.5, 33));
	ASSERT_EQ(-0.5 * b, ComplexDicart(-16.05, -5.7));
	b = ComplexDicart();
	ASSERT_EQ(a * b, b);
	ASSERT_EQ(b * a, b);
	b = ComplexDicart(1.0);
	ASSERT_EQ(a * b, a);
	ASSERT_EQ(b * a, a);
}

TEST_F(TestComplexDicart, division){
	a = ComplexDicart(14.2, 13.2);
	b = ComplexDicart(32.1, 11.4);
	ComplexDicart t = a / b;
	ASSERT_NEAR(t.real(), 0.522505752, 0.00000001);
	ASSERT_NEAR(t.imaginary(), 0.22565216, 0.00000001);
	t = b / a;
	ASSERT_NEAR(t.real(), 1.613014791, 0.00000001);
	ASSERT_NEAR(t.imaginary(), -0.6966053, 0.00000001);
	t = a / 2.0;
	ASSERT_NEAR(t.real(), 7.1, 0.00000001);
	ASSERT_NEAR(t.imaginary(), 6.6, 0.00000001);
	t = 100.0 / b;
	ASSERT_NEAR(t.real(), 2.7663590068, 0.00000001);
	ASSERT_NEAR(t.imaginary(), -0.9824452545309, 0.00000001);
}

TEST_F(TestComplexDicart, abs_angle_abs2){
	a = ComplexDicart(14.2, 13.2);
	ASSERT_NEAR(a.abs(), 19.387624919004, 0.00000001);
	ASSERT_NEAR(a.abs2(), 375.88, 0.00000001);
	ASSERT_NEAR(a.angle(), 0.7489180042744986, 0.00000001);
	b = ComplexDicart(32.1, -11.4);
	ASSERT_NEAR(b.abs(), 34.06420408581419, 0.00000001);
	ASSERT_NEAR(b.abs2(), 1160.37, 0.00000001);
	ASSERT_NEAR(b.angle(), -0.34124669110708716, 0.00000001);
	a = ComplexDicart(-14.2, 13.2);
	ASSERT_NEAR(a.angle(), 2.392674649315, 0.00000001);
	b = ComplexDicart(-32.1, -11.4);
	ASSERT_NEAR(b.angle(), -2.800345962482706, 0.00000001);
	a = ComplexDicart();
	ASSERT_EQ(a.angle(), 0.0);
}

TEST_F(TestComplexDicart, pow){
	a = ComplexDicart(14.2, 13.2);
	ComplexDicart t = a.pow(2);
	ASSERT_NEAR(t.real(), 27.4, 0.00000001);
	ASSERT_NEAR(t.imaginary(), 374.8799999999999, 0.00000001);
	t = a.pow(-2);
	ASSERT_NEAR(t.real(), 0.00019393318341, 0.00000001);
	ASSERT_NEAR(t.imaginary(), -0.002653345686, 0.00000001);
	t = a.pow(1);
	ASSERT_NEAR(t.real(), a.real(), 0.00000001);
	ASSERT_NEAR(t.imaginary(), a.imaginary(), 0.00000001);
	t = a.pow(0);
	ASSERT_NEAR(t.real(), 1.0, 0.00000001);
	ASSERT_NEAR(t.imaginary(), 0.0, 0.00000001);
}

TEST_F(TestComplexDicart, to_s){
	a = ComplexDicart(14.2, 13.2);
	ASSERT_EQ(a.to_s(), "(14.2) + (13.2)i");
	a = ComplexDicart();
	ASSERT_EQ(a.to_s(), "(0) + (0)i");
}

TEST_F(TestComplexDicart, conjugate){
	a = ComplexDicart(14.2, 13.2);
	b = a.conjugate();
	ASSERT_EQ(a.real(), b.real());
	ASSERT_EQ(a.imaginary(), -b.imaginary());
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