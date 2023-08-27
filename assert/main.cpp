#include <cassert>

struct Version {
    bool locked;
    bool inserting;
    bool splitting;
};

int main() {
    Version v = {true, false, false};

    assert(v.locked && !v.inserting && !v.splitting);

    return 0;
}