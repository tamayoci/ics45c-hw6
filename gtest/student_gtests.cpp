// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the shapes and Picture. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the areas, for print_all and draw_all,
// for total_area, and for copying a Picture.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include <sstream>

TEST(ShapeTests, RectangleAreaIsWidthTimesHeight) {
    EXPECT_NEAR(Rectangle({0, 0}, "R", 7, 3).area(), 21.0, 0.001);
}

TEST(PictureTests, AnEmptyPictureHasNoArea) {
    const Picture p;
    EXPECT_DOUBLE_EQ(p.total_area(), 0.0);
}

TEST(ShapeTests, CircleArea) {
    Circle c({0, 0}, "C", 3);
    EXPECT_NEAR(c.area(), 28.27433388, 0.0001);
}

TEST(ShapeTests, TriangleArea) {
    Triangle t({0, 0}, "T", 8, 5);
    EXPECT_DOUBLE_EQ(t.area(), 20.0);
}

TEST(ShapeTests, SquareArea) {
    Square s({0, 0}, "S", 5);
    EXPECT_DOUBLE_EQ(s.area(), 25.0);
}

TEST(ShapeTests, ZeroArea) {
    Circle c({0, 0}, "C", 0);
    Triangle t({0, 0}, "T", 0, 5);

    EXPECT_DOUBLE_EQ(c.area(), 0.0);
    EXPECT_DOUBLE_EQ(t.area(), 0.0);
}

TEST(ShapeTests, PrintFormat) {
    Rectangle r({2, 3}, "Rect", 4, 5);
    std::ostringstream out;

    r.print(out);

    EXPECT_EQ(out.str(), "Rect at (2, 3) area = 20\n");
}

TEST(ShapeTests, CloneWorks) {
    Rectangle r({1, 2}, "R", 4, 5);
    Shape* copy = r.clone();

    EXPECT_NE(copy, &r);
    EXPECT_DOUBLE_EQ(copy->area(), 20.0);

    delete copy;
}

TEST(PictureTests, AddMultipleShapes) {
    Picture p;

    Rectangle r({0, 0}, "R", 4, 5);
    Square s({0, 0}, "S", 3);

    p.add(r);
    p.add(s);

    EXPECT_DOUBLE_EQ(p.total_area(), 29.0);
}

TEST(PictureTests, DrawAllInOrder) {
    Picture p;

    Rectangle r1({0, 0}, "R1", 2, 2);
    Rectangle r2({0, 0}, "R2", 4, 2);

    p.add(r1);
    p.add(r2);

    std::ostringstream out;
    p.draw_all(out);

    EXPECT_EQ(out.str(), "**\n****\n");
}

TEST(PictureTests, PrintAllInOrder) {
    Picture p;

    Rectangle r1({0, 0}, "R1", 2, 2);
    Rectangle r2({1, 1}, "R2", 3, 2);

    p.add(r1);
    p.add(r2);

    std::ostringstream out;
    p.print_all(out);

    EXPECT_EQ(out.str(),
        "R1 at (0, 0) area = 4\n"
        "**\n"
        "R2 at (1, 1) area = 6\n"
        "***\n");
}

TEST(PictureTests, CopyConstructor) {
    Picture p1;

    Rectangle r({0, 0}, "R", 4, 5);
    p1.add(r);

    Picture p2(p1);

    EXPECT_DOUBLE_EQ(p2.total_area(), 20.0);

    Square s({0, 0}, "S", 3);
    p1.add(s);

    EXPECT_DOUBLE_EQ(p1.total_area(), 29.0);
    EXPECT_DOUBLE_EQ(p2.total_area(), 20.0);
}

TEST(PictureTests, CopyAssignment) {
    Picture p1;
    Picture p2;

    Rectangle r({0, 0}, "R", 4, 5);
    Square s({0, 0}, "S", 3);

    p1.add(r);
    p2.add(s);

    p2 = p1;

    EXPECT_DOUBLE_EQ(p2.total_area(), 20.0);
}

TEST(PictureTests, AddClonesShape) {
    Picture p;

    {
        Rectangle r({0, 0}, "R", 5, 4);
        p.add(r);
    }

    EXPECT_DOUBLE_EQ(p.total_area(), 20.0);
}
