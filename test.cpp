#include <gtest/gtest.h>
#include "common.cpp"

TEST(Solution, Positive) {
    MiniCassandra db;
    db.insert("Linkedin", 7, "DGFINL");
    db.query("Apple", 7, 8);
    db.insert("Airbnb", 8, "BOKAQP");
    db.insert("Linkedin", 3, "ODAMGH");
    db.insert("Linkedin", 3, "KELFJN");
    auto results = db.query("Linkedin", 3, 7);
    ASSERT_EQ("KELFJN", results[0].value);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}