#include <gtest/gtest.h>
#include "../include/Account.h"

TEST(AccountTest, DefaultConstructorInitializesFields) {
    Account acc;
    EXPECT_EQ(acc.get_name(), "");
    EXPECT_EQ(acc.get_balance(), 0);
    EXPECT_EQ(acc.get_id(), -1);
}

TEST(AccountTest, ConstructorSetsFields) {
    Account acc("Alice", "1234", 5000);  // password value doesn't matter here
    EXPECT_EQ(acc.get_name(), "Alice");
    EXPECT_EQ(acc.get_balance(), 5000);
    EXPECT_EQ(acc.get_id(), -1);  // default ID
}

TEST(AccountTest, SetNameWorks) {
    Account acc;
    acc.set_name("Bob");
    EXPECT_EQ(acc.get_name(), "Bob");
}

TEST(AccountTest, SetBalanceWorks) {
    Account acc;
    acc.set_balance(10000);
    EXPECT_EQ(acc.get_balance(), 10000);
}

TEST(AccountTest, SetIdWorks) {
    Account acc;
    acc.set_id(42);
    EXPECT_EQ(acc.get_id(), 42);
}

TEST(AccountTest, ToJsonReturnsCorrectJson) {
    Account acc("Charlie", "0000", 7000);
    acc.set_id(101);
    json j = acc.to_json();

    EXPECT_EQ(j["name"], "Charlie");
    EXPECT_EQ(j["balance"], 7000);
    EXPECT_EQ(j["id"], 101);
}

TEST(AccountTest, FromJsonCreatesCorrectAccount) {
    json j = {
        {"name", "Dana"},
        {"password", "1234"},  // ignored in logic
        {"balance", 9000},
        {"id", 77}
    };

    Account acc = Account::from_json(j);
    EXPECT_EQ(acc.get_name(), "Dana");
    EXPECT_EQ(acc.get_balance(), 9000);
    EXPECT_EQ(acc.get_id(), 77);
}

int main (int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
