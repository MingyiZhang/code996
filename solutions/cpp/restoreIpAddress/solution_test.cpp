//
// Created by mingyi on 24.05.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<string, vector<string>> TStruct;

class RestoreIpAddressesTest
    : public ::testing::TestWithParam<TStruct> {
};

TEST_P(RestoreIpAddressesTest, Test) {
  TStruct tt = GetParam();
  vector<string> actual = restoreIpAddress(tt.input);
  ASSERT_THAT(actual, UnorderedElementsAreArray(tt.expected));
}

INSTANTIATE_TEST_SUITE_P(Tests, RestoreIpAddressesTest, ::testing::Values(
    TStruct{
        .input = "25525511135",
        .expected = {"255.255.11.135", "255.255.111.35"}
    },
    TStruct{
        .input = "0000",
        .expected = {"0.0.0.0"}
    }
));

