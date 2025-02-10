#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
using namespace std;

TEST(TEST, TEST_TEST) {
    string name = "To Kill a Mocking Bird";
    string genre = "Romance";
    int pages = 352;

    Book book();
    string name_of_book = book.getName();

    EXPECT_EQ(name_of_book.c_str(), name);


}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);


    return RUN_ALL_TESTS();
}