#include "doctest.h"
#include "Board.hpp"

using namespace std;
using namespace ariel;

Board board;

TEST_CASE("read- empty board")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 1, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(1, 1, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(32, 55, Direction::Horizontal, 3) == string("___"));
    CHECK(board.read(32, 55, Direction::Vertical, 3) == string("___"));
    CHECK(board.read(12, 40, Direction::Horizontal, 6) == string("______"));
    CHECK(board.read(12, 40, Direction::Vertical, 6) == string("______"));
    CHECK(board.read(50, 60, Direction::Horizontal, 9) == string("_________"));
    CHECK(board.read(50, 60, Direction::Vertical, 9) == string("_________"));
}

TEST_CASE("post")
{
    // 1 post for each point
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Message"));
    CHECK_NOTHROW(board.post(1, 5, Direction::Horizontal, "Petah"));
    CHECK_NOTHROW(board.post(6, 0, Direction::Horizontal, "Project"));
    CHECK_NOTHROW(board.post(8, 4, Direction::Horizontal, "Roni"));
    CHECK_NOTHROW(board.post(15, 2, Direction::Horizontal, "Good"));
    CHECK_NOTHROW(board.post(16, 15, Direction::Horizontal, "Luck"));

    CHECK_NOTHROW(board.post(2, 0, Direction::Vertical, "Hi"));
    CHECK_NOTHROW(board.post(9, 3, Direction::Vertical, "Hallo"));
    CHECK_NOTHROW(board.post(5, 12, Direction::Vertical, "Welcome"));
    CHECK_NOTHROW(board.post(17, 4, Direction::Vertical, "Cpp"));
    CHECK_NOTHROW(board.post(20, 2, Direction::Vertical, "W"));
    CHECK_NOTHROW(board.post(15, 14, Direction::Vertical, "Yes"));

    //2 posts at the same point
    CHECK_NOTHROW(board.post(8, 7, Direction::Horizontal, "Harel"));
    CHECK_NOTHROW(board.post(6, 4, Direction::Horizontal, "New"));
    CHECK_NOTHROW(board.post(17, 4, Direction::Horizontal, "Table"));

    CHECK_NOTHROW(board.post(1, 9, Direction::Vertical, "Tiqwa"));
    CHECK_NOTHROW(board.post(16, 14, Direction::Vertical, "No"));
    CHECK_NOTHROW(board.post(11, 12, Direction::Vertical, "Every"));

    //3 posts at the same point
    CHECK_NOTHROW(board.post(17, 12, Direction::Horizontal, "Wow"));

    CHECK_NOTHROW(board.post(4, 5, Direction::Vertical, "Dog"));
}

TEST_CASE("read- after posts")
{
    CHECK(board.read(15, 2, Direction::Horizontal, 5) == string("Good_"));
    CHECK(board.read(1, 5, Direction::Horizontal, 6) == string("PetaT_"));
    CHECK(board.read(8, 4, Direction::Horizontal, 8) == string("RonHarel"));
    CHECK(board.read(8, 4, Direction::Horizontal, 10) == string("RonHarelc_"));
    CHECK(board.read(15, 12, Direction::Horizontal, 4) == string("y_Y_"));
    CHECK(board.read(6, 0, Direction::Horizontal, 7) == string("ProjNgw"));

    CHECK(board.read(15, 14, Direction::Vertical, 4) == string("YNw_"));
    CHECK(board.read(17, 4, Direction::Vertical, 3) == string("tpp"));
    CHECK(board.read(5, 12, Direction::Vertical, 11) == string("WelcomEvery"));
    CHECK(board.read(17, 2, Direction::Vertical, 4) == string("____W"));
}

TEST_CASE("specil symbols")
{
    CHECK_NOTHROW(board.post(12, 20, Direction::Horizontal, "?&"));
    CHECK(board.read(12, 20, Direction::Horizontal, 2) == "?&");
    CHECK_NOTHROW(board.post(13, 19, Direction::Horizontal, "@"));
    CHECK(board.read(13, 19, Direction::Horizontal, 1) == "@");
    CHECK_NOTHROW(board.post(8, 17, Direction::Vertical, "%"));
    CHECK(board.read(8, 17, Direction::Vertical, 1) == "%");
    CHECK_NOTHROW(board.post(0, 16, Direction::Vertical, "123*"));
    CHECK(board.read(0, 16, Direction::Vertical, 4) == "123*");
}
