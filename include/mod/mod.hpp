#ifndef B165F7C4_5C9A_4D64_AB4D_6593AC2A743B
#define B165F7C4_5C9A_4D64_AB4D_6593AC2A743B

#include <tbb/parallel_for.h>
#include <tbb/concurrent_priority_queue.h>

class Mod
{
    tbb::concurrent_priority_queue<int, std::greater<int>> queue;

public:
    Mod() = default;
    ~Mod() = default;

    void run();
};

#endif /* B165F7C4_5C9A_4D64_AB4D_6593AC2A743B */
