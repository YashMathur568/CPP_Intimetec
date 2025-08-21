#include "gtest/gtest.h"
#include "Admin.h"
#include "MockBank.h"

class AdminTest : public ::testing::Test
{
protected:
    Admin *admin;
    MockBank *mockBank;

    void SetUp() override
    {
        mockBank = new MockBank();
        admin = new Admin(100001, "Admin", 22, "admin@gmail.com", "9876543210", "adminpass");
    }

    void TearDown() override
    {
        delete admin;
        delete mockBank;
    }
};

TEST_F(AdminTest, CreateAccountForAccountHolder)
{
    AccountHolder accHolder(1001, "Ramesh Kumar", 30, "rameshKumar@gmail.com", "1234567890", "pass@123", 10001);

    EXPECT_CALL(*mockBank, createAccount(accHolder, *admin))
        .Times(1)
        .WillOnce(::testing::Return(true));

    bool result = mockBank->createAccount(accHolder, *admin);
    EXPECT_TRUE(result);
}

TEST_F(AdminTest, SearchAccountByNumber)
{
    int accountNumber = 10001;
    Account mockAccount(accountNumber);

    EXPECT_CALL(*mockBank, searchAccount(accountNumber, *admin))
        .Times(1)
        .WillOnce(::testing::Return(&mockAccount));

    Account *account = mockBank->searchAccount(accountNumber, *admin);
    EXPECT_EQ(account->getAccountNumber(), accountNumber);
}

TEST_F(AdminTest, CloseAccount)
{
    int accountNumber = 10001;

    EXPECT_CALL(*mockBank, closeAccount(accountNumber, *admin))
        .Times(1);

    mockBank->closeAccount(accountNumber, *admin);
}
