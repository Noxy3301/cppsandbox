#include <iostream>
#include <bitset>

// unionは先に宣言したやつがビット列の下に来る(この場合だとlockedが最上位ビット、v_splitが下位16ビット)

struct test {
    union {
        uint32_t obj_;
        struct {
            uint16_t v_split : 16;
            uint8_t v_insert : 8;
            bool unused : 2;
            bool isBorder : 1;
            bool isRoot : 1;
            bool deleted : 1;
            bool splitting : 1;
            bool inserting : 1;
            bool locked : 1;
        };
    };

  test() noexcept
    : locked{false}
    , inserting{false}
    , splitting{false}
    , deleted{false}
    , isRoot{false}
    , isBorder{false}
    , v_split{1}
    , v_insert{0}
  {}
};

class TestObj {
    public:
        test testObj_;
};

int main() {
    TestObj *test = new TestObj();

    std::cout << uint32_t(test->testObj_.obj_) << std::endl;

    return 0;
}