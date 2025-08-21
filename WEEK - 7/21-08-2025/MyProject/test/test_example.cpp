#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Account.h"
#include "MockNotificationService.h"

TEST(AccountTest, DepositSendsNotification)
{
    MockNotificationService mockService;

    Account acc(1, &mockService);

    EXPECT_CALL(mockService, sendNotification("Deposit Successful"))
        .Times(1);

    acc.deposit(1000);

    EXPECT_EQ(acc.getBalance(), 1000);
}
