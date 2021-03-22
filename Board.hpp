#include <string>
#include "Direction.hpp"

namespace ariel
{
    class Board {
    public:
        Board(){}
        ~Board(){}
        static void post(uint row, uint col, Direction direct, const std::string &message);
        static std::string read(uint row, uint col, Direction direct, uint length);
        static void show();
    };
}