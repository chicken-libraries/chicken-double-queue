//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "chicken/double-queue.h"
#include <unity.h>

DeQueueOf *queue;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    queue = chickenDeQueueCreate();
} // end of function setUp

void tearDown(void)
{
    chickenDeQueueErase(&queue);
} // end of function tearDown

//
// list of all the test cases for this project
//
static void test_chickenDeQueuePushStart(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenDeQueuePushStart(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", chickenDeQueuePeekStart(queue));

    chickenDeQueuePushStart(queue, "2077");
    chickenDeQueuePushStart(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2010", chickenDeQueuePeekStart(queue));
} // end of test case

static void test_chickenDeQueuePushStart_withNullptr(void)
{
    chickenDeQueuePushStart(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));

    chickenDeQueuePushStart(NULL, "2077");
    chickenDeQueuePushStart(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
} // end of test case

static void test_chickenDeQueuePushEnd(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenDeQueuePushEnd(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", chickenDeQueuePeekStart(queue));
    TEST_ASSERT_EQUAL_STRING("2021", chickenDeQueuePeekEnd(queue));

    chickenDeQueuePushEnd(queue, "2077");
    chickenDeQueuePushEnd(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2021", chickenDeQueuePeekStart(queue));
    TEST_ASSERT_EQUAL_STRING("2010", chickenDeQueuePeekEnd(queue));
} // end of test case

static void test_chickenDeQueuePushEnd_withNullptr(void)
{
    chickenDeQueuePushEnd(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekEnd(queue));

    chickenDeQueuePushEnd(NULL, "2077");
    chickenDeQueuePushEnd(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekEnd(queue));
} // end of test case

static void test_chickenDeQueuePopStart(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenDeQueuePushStart(queue, "red chicken");
    chickenDeQueuePushStart(queue, "blue chicken");
    chickenDeQueuePushStart(queue, "black chicken");
    chickenDeQueuePushStart(queue, "green chicken");
    chickenDeQueuePushStart(queue, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("yellow chicken", chickenDeQueuePeekStart(queue));
    chickenDeQueuePopStart(queue);
    TEST_ASSERT_EQUAL_STRING("green chicken", chickenDeQueuePeekStart(queue));
    chickenDeQueuePopStart(queue);
    TEST_ASSERT_EQUAL_STRING("black chicken", chickenDeQueuePeekStart(queue));

} // end of test case

// static void test_chickenDeQueuePopStart_withNullptr(void)
// {
//     chickenDeQueuePushStart(NULL, "red chicken");
//     chickenDeQueuePushStart(NULL, "blue chicken");
//     chickenDeQueuePushStart(NULL, "black chicken");

//     TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
//     chickenDeQueuePopStart(queue);
//     TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
// } // end of test case

static void test_chickenDeQueuePopEnd(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenDeQueuePushEnd(queue, "red chicken");
    chickenDeQueuePushEnd(queue, "blue chicken");
    chickenDeQueuePushEnd(queue, "black chicken");
    chickenDeQueuePushEnd(queue, "green chicken");
    chickenDeQueuePushEnd(queue, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenDeQueuePeekStart(queue));
    chickenDeQueuePopEnd(queue);
    TEST_ASSERT_EQUAL_STRING("red chicken", chickenDeQueuePeekStart(queue));
    chickenDeQueuePopEnd(queue);
    TEST_ASSERT_EQUAL_STRING("red chicken", chickenDeQueuePeekStart(queue));

} // end of test case

// static void test_chickenDeQueuePopEnd_withNullptr(void)
// {
//     chickenDeQueuePushEnd(NULL, "red chicken");
//     chickenDeQueuePushEnd(NULL, "blue chicken");
//     chickenDeQueuePushEnd(NULL, "black chicken");

//     TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
//     chickenDeQueuePopEnd(queue);
//     TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
// } // end of test case



static void test_chickenDeQueueItsEmpty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(chickenDeQueueItsEmpty(queue));
    chickenDeQueuePushStart(queue, "red chicken");
    TEST_ASSERT_FALSE(chickenDeQueueItsEmpty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenDeQueuePeekStart(queue));
} // end of test case

static void test_chickenDeQueueItsEmpty_withNullptr(void)
{
    chickenDeQueuePushStart(NULL, "red chicken");
    TEST_ASSERT_TRUE(chickenDeQueueItsEmpty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
} // end of test case

static void test_chickenDeQueueNotEmpty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_FALSE(chickenDeQueueNotEmpty(queue));
    chickenDeQueuePushStart(queue, "red chicken");
    TEST_ASSERT_TRUE(chickenDeQueueNotEmpty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenDeQueuePeekStart(queue));
} // end of test case

static void test_chickenDeQueueNotEmpty_withNullptr(void)
{
    chickenDeQueuePushStart(NULL, "red chicken");
    TEST_ASSERT_FALSE(chickenDeQueueNotEmpty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, chickenDeQueuePeekStart(queue));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_chickenDeQueuePushStart);
    RUN_TEST(test_chickenDeQueuePushEnd);
    RUN_TEST(test_chickenDeQueuePopStart);
    RUN_TEST(test_chickenDeQueuePopEnd);
    RUN_TEST(test_chickenDeQueueItsEmpty);
    RUN_TEST(test_chickenDeQueueNotEmpty);
    RUN_TEST(test_chickenDeQueuePushStart_withNullptr);
    RUN_TEST(test_chickenDeQueuePushEnd_withNullptr);
    // RUN_TEST(test_chickenDeQueuePopStart_withNullptr);
    // RUN_TEST(test_chickenDeQueuePopEnd_withNullptr);
    RUN_TEST(test_chickenDeQueueItsEmpty_withNullptr);
    RUN_TEST(test_chickenDeQueueNotEmpty_withNullptr);

    return UNITY_END();
} // end of function main
