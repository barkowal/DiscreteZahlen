#include <gtest/gtest.h>

extern "C"{
#include "nwd_nww.h"
}

struct Parameters{
	int a;
	int b;
	int expectedReturn;

	friend std::ostream& operator<<(std::ostream& os, const Parameters& obj){
		return os
		<<"a: "<<obj.a
		<<", b: "<<obj.b
		<<", expected: "<<obj.expectedReturn;
	}
};

struct stringParameters{
	int a;
	int b;
	std::string expectedReturn;

	friend std::ostream& operator<<(std::ostream& os, const stringParameters& obj){
		return os
		<<"a: "<<obj.a
		<<", b: "<<obj.b
		<<", expected: "<<obj.expectedReturn;
	}
};


class nwd_nww_pow_TEST : public testing::TestWithParam<Parameters>{
};
class nwd_nww_prime_TEST: public testing::TestWithParam<Parameters>{
};
class nwd_nww_nextPrime_TEST : public testing::TestWithParam<Parameters>{
};
class nwd_nww_calculation_TEST : public testing::TestWithParam<stringParameters>{
};
class nwd_nww_factorization_TEST : public testing::TestWithParam<stringParameters>{
};

//fastPow()
TEST_P(nwd_nww_pow_TEST, power_TESTS){
	Parameters params = GetParam();
	int result = fastPow(params.a, params.b);
	EXPECT_EQ(params.expectedReturn, result);
}

INSTANTIATE_TEST_CASE_P(power_TEST_SUITE, nwd_nww_pow_TEST, testing::Values(
	Parameters{2,2,4},
	Parameters{6,0,1},
	Parameters{0,0,1},
	Parameters{-4,2,16}
));


//isPrime()
TEST_P(nwd_nww_prime_TEST, isPrime_TESTS){
	Parameters params = GetParam();
	int result = isPrime(params.a);
	EXPECT_EQ(params.expectedReturn, result);
}

INSTANTIATE_TEST_CASE_P(isPrime_TEST_SUITE, nwd_nww_prime_TEST, testing::Values(
	Parameters{2,0,TRUE},
	Parameters{6,0,FALSE},
	Parameters{13,0,TRUE},
	Parameters{1,0,FALSE}
));


//getNextPrime()
TEST_P(nwd_nww_nextPrime_TEST, nextPrime_TESTS){
	Parameters params = GetParam();
	int result = getNextPrime(params.a);
	EXPECT_EQ(params.expectedReturn, result);
}

INSTANTIATE_TEST_CASE_P(nextPrime_TEST_SUITE, nwd_nww_nextPrime_TEST, testing::Values(
	Parameters{2,0,3},
	Parameters{8,0,11},
	Parameters{0,0,2},
	Parameters{17,0,19}
));


//NWD_NWW()
TEST_P(nwd_nww_calculation_TEST, NWD_NWW_TESTS){
	stringParameters params = GetParam();
	factor result = calculateNWD_NWW(params.a, params.b);
	std::string functionOutput = result.nwdSequence;
	functionOutput.append(result.nwwSequence);
	EXPECT_EQ(params.expectedReturn, functionOutput);
}

INSTANTIATE_TEST_CASE_P(NWD_TEST_SUITE, nwd_nww_calculation_TEST, testing::Values(
	stringParameters{10,5," 2^0 5^1 2^1 5^1"},
	stringParameters{5,25," 5^1 5^2"},
	stringParameters{13,17," 13^0 17^0 13^1 17^1"},
	stringParameters{1,1,""}
));


//getFactorization()
TEST_P(nwd_nww_factorization_TEST, NWD_NWW_TESTS){
	stringParameters params = GetParam();
	char* result = getFactorization(params.a);
	EXPECT_EQ(params.expectedReturn, result);
}

INSTANTIATE_TEST_CASE_P(FACTORIZATION_TEST_SUITE, nwd_nww_factorization_TEST, testing::Values(
	stringParameters{10,0," 2^1 5^1"},
	stringParameters{90,0," 2^1 3^2 5^1"},
	stringParameters{1,0,""},
	stringParameters{89,0," 89^1"}
));
