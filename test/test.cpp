//#include <iostream>
#include <gmock/gmock.h>
#include <complex.h>
#include <iostream>
#include <cmath>

#define EPS 0.00000001

using namespace std;

class TestComplexDicart : public ::testing::Test{
protected:
	void SetUp(){

	}

	void TearDown(){

	}

	ComplexDicart a;
	ComplexDicart b;
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
	a = Complex(ComplexPolar(12, 0.3));
	ASSERT_NEAR(a.real(), 11.464037869507, EPS);
	ASSERT_NEAR(a.imaginary(), 3.5462424799, EPS);

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
	ASSERT_NEAR(t.real(), 0.522505752, EPS);
	ASSERT_NEAR(t.imaginary(), 0.22565216, EPS);
	t = b / a;
	ASSERT_NEAR(t.real(), 1.613014791, EPS);
	ASSERT_NEAR(t.imaginary(), -0.6966053, EPS);
	t = a / 2.0;
	ASSERT_NEAR(t.real(), 7.1, EPS);
	ASSERT_NEAR(t.imaginary(), 6.6, EPS);
	t = 100.0 / b;
	ASSERT_NEAR(t.real(), 2.7663590068, EPS);
	ASSERT_NEAR(t.imaginary(), -0.9824452545309, EPS);
}

TEST_F(TestComplexDicart, abs_angle_abs2){
	a = ComplexDicart(14.2, 13.2);
	ASSERT_NEAR(a.abs(), 19.387624919004, EPS);
	ASSERT_NEAR(a.abs2(), 375.88, EPS);
	ASSERT_NEAR(a.angle(), 0.7489180042744986, EPS);
	b = ComplexDicart(32.1, -11.4);
	ASSERT_NEAR(b.abs(), 34.06420408581419, EPS);
	ASSERT_NEAR(b.abs2(), 1160.37, EPS);
	ASSERT_NEAR(b.angle(), -0.34124669110708716, EPS);
	a = ComplexDicart(-14.2, 13.2);
	ASSERT_NEAR(a.angle(), 2.392674649315, EPS);
	b = ComplexDicart(-32.1, -11.4);
	ASSERT_NEAR(b.angle(), -2.800345962482706, EPS);
	a = ComplexDicart();
	ASSERT_EQ(a.angle(), 0.0);
}

TEST_F(TestComplexDicart, pow){
	a = ComplexDicart(14.2, 13.2);
	ComplexDicart t = a.pow(2);
	ASSERT_NEAR(t.real(), 27.4, EPS);
	ASSERT_NEAR(t.imaginary(), 374.8799999999999, EPS);
	t = a.pow(-2);
	ASSERT_NEAR(t.real(), 0.00019393318341, EPS);
	ASSERT_NEAR(t.imaginary(), -0.002653345686, EPS);
	t = a.pow(1);
	ASSERT_NEAR(t.real(), a.real(), EPS);
	ASSERT_NEAR(t.imaginary(), a.imaginary(), EPS);
	t = a.pow(0);
	ASSERT_NEAR(t.real(), 1.0, EPS);
	ASSERT_NEAR(t.imaginary(), 0.0, EPS);
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

class TestComplexPolar : public ::testing::Test{
protected:
	void SetUp(){

	}

	void TearDown(){

	}

	ComplexPolar a;
	ComplexPolar b;
	Complex* dic;
};

TEST_F(TestComplexPolar, polar_constructor){
	a = ComplexPolar();
	ASSERT_EQ(a.abs(), 0.0);
	ASSERT_EQ(a.angle(), 0.0);
	a = ComplexPolar(14.0);
	ASSERT_EQ(a.abs(), 14.0);
	ASSERT_EQ(a.angle(), 0.0);
	a = ComplexPolar(23.6, 0.0);
	ASSERT_EQ(a.abs(), 23.6);
	ASSERT_EQ(a.angle(), 0.0);
	a = ComplexPolar(0.0, 24.5);
	ASSERT_EQ(a.abs(), 0.0);
	ASSERT_EQ(a.angle(), 0.0);
	a = ComplexPolar(16.0, 12.1);
	ASSERT_EQ(a.abs(), 16.0);
	ASSERT_EQ(a.angle(), -0.4663706143591733);
	a = ComplexPolar(16.0, 12.1);
	ASSERT_EQ(a.abs(), 16.0);
	ASSERT_EQ(a.angle(), -0.4663706143591733);
	ComplexPolar t1(a);
	ASSERT_EQ(t1.abs(), 16.0);
	ASSERT_EQ(t1.angle(), -0.4663706143591733);
	ComplexPolar t2 = a;
	ASSERT_EQ(t2.abs(), 16.0);
	ASSERT_EQ(t2.angle(), -0.4663706143591733);
	t2 = ComplexDicart(12.2, 13.0);
	ASSERT_NEAR(t2.abs(), 17.82806775845, EPS);
	ASSERT_NEAR(t2.angle(), 0.8171335369259, EPS);
}

TEST_F(TestComplexPolar, dicart_abs2){
	a = ComplexPolar(13.0, 1.1);
	ASSERT_NEAR(a.real(), 5.8967495785, EPS);
	ASSERT_NEAR(a.imaginary(), 11.585695681, EPS);
	a = ComplexPolar();
	ASSERT_NEAR(a.real(), 0.0, EPS);
	ASSERT_NEAR(a.imaginary(), 0.0, EPS);
	a = ComplexPolar(13.0, 5.1);
	ASSERT_NEAR(a.real(), 4.91371065527, EPS);
	ASSERT_NEAR(a.imaginary(), -12.0355908703, EPS);
	a = ComplexPolar(13.0, 4.1);
	ASSERT_NEAR(a.real(), -7.4727113049, EPS);
	ASSERT_NEAR(a.imaginary(), -10.63760244, EPS);
	a = ComplexPolar(13.0, 3.1);
	ASSERT_NEAR(a.real(), -12.98875695355, EPS);
	ASSERT_NEAR(a.imaginary(), 0.5405486116, EPS);
	ASSERT_NEAR(a.abs2(), 169.0, EPS);
}

TEST_F(TestComplexPolar, conjugate){
	a = ComplexPolar(13.0, 1.1);
	b = a.conjugate();
	ASSERT_NEAR(b.real(), a.real(), EPS);
	ASSERT_NEAR(b.imaginary(), -a.imaginary(), EPS);
	a = ComplexPolar(23.0, -21.1);
	b = a.conjugate();
	ASSERT_NEAR(b.real(), a.real(), EPS);
	ASSERT_NEAR(b.imaginary(), -a.imaginary(), EPS);
}

TEST_F(TestComplexPolar, negative_number){
	a = ComplexPolar(13.0, 1.1);
	b = -a;
	ASSERT_NEAR(b.real(), -a.real(), EPS);
	ASSERT_NEAR(b.imaginary(), -a.imaginary(), EPS);
	a = ComplexPolar(23.0, -21.1);
	b = -a;
	ASSERT_NEAR(b.real(), -a.real(), EPS);
	ASSERT_NEAR(b.imaginary(), -a.imaginary(), EPS);

}

TEST_F(TestComplexPolar, pow){
	a = ComplexPolar(13.0, 1.4);
	b = a.pow(2);
	ASSERT_NEAR(b.real(), -159.235575573003, EPS);
	ASSERT_NEAR(b.imaginary(), 56.612997376348, EPS);
	b = a.pow(-2);
	ASSERT_NEAR(b.real(), -0.0055752801223, EPS);
	ASSERT_NEAR(b.imaginary(), -0.00198217840329, EPS);
}

TEST_F(TestComplexPolar, to_s){
	a = ComplexPolar(13.0, 1.4);
	ASSERT_EQ(a.to_s(), "13(cos(1.4)+i sin(1.4))");
}

TEST_F(TestComplexPolar, adding){
	a = ComplexPolar(13.0, 1.4);
	b = ComplexPolar(7.0, 6.0);
	ComplexPolar t = a + b;
	ASSERT_NEAR(t.real(), 8.93076486426, EPS);
	ASSERT_NEAR(t.imaginary(), 10.85493800246, EPS);
	t = a + 5.0;
	ASSERT_NEAR(t.real(), 7.209572857703, EPS);
	ASSERT_NEAR(t.imaginary(), 12.81084648985, EPS);
	t = 3.0 + b;
	ASSERT_NEAR(t.real(), 9.72119200655, EPS);
	ASSERT_NEAR(t.imaginary(), -1.95590848739, EPS);
}

TEST_F(TestComplexPolar, difference){
	a = ComplexPolar(13.0, 1.4);
	b = ComplexPolar(7.0, 6.0);
	ComplexPolar t = a - b;
	ASSERT_NEAR(t.real(), -4.511619148849, EPS);
	ASSERT_NEAR(t.imaginary(), 14.76675497724, EPS);
	t = a - 5.0;
	ASSERT_NEAR(t.real(), -2.7904271422969, EPS);
	ASSERT_NEAR(t.imaginary(), 12.81084648985, EPS);
	t = 3.0 - b;
	ASSERT_NEAR(t.real(), -3.721192006553, EPS);
	ASSERT_NEAR(t.imaginary(), 1.95590848739, EPS);
}

TEST_F(TestComplexPolar, multiple){
	a = ComplexPolar(13.0, 1.4);
	b = ComplexPolar(7.0, 6.0);
	ComplexPolar t = a * b;
	ASSERT_NEAR(t.real(), 39.90780680927, EPS);
	ASSERT_NEAR(t.imaginary(), 81.78243671886, EPS);
	t = a * 5.0;
	ASSERT_NEAR(t.real(), 11.047864288516, EPS);
	ASSERT_NEAR(t.imaginary(), 64.05423244925, EPS);
	t = 3.0 * b;
	ASSERT_NEAR(t.real(), 20.163576019658, EPS);
	ASSERT_NEAR(t.imaginary(), -5.867725462177, EPS);
}

TEST_F(TestComplexPolar, division){
	a = ComplexPolar(13.0, 1.4);
	b = ComplexPolar(7.0, 6.0);
	ComplexPolar t = a / b;
	ASSERT_NEAR(t.real(), -0.208283264308, EPS);
	ASSERT_NEAR(t.imaginary(), 1.845426149605, EPS);
	t = a / 5.0;
	ASSERT_NEAR(t.real(), 0.4419145715406, EPS);
	ASSERT_NEAR(t.imaginary(), 2.56216929797, EPS);
	t = 3.0 / b;
	ASSERT_NEAR(t.real(), 0.4115015514216, EPS);
	ASSERT_NEAR(t.imaginary(), 0.119749499228, EPS);
}

TEST_F(TestComplexPolar, polymorf){
	dic = new ComplexPolar(12, 0.3);
	ASSERT_NEAR(dic->real(), 11.464037869507, EPS);
	ASSERT_NEAR(dic->imaginary(), 3.5462424799, EPS);
	delete dic;
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}