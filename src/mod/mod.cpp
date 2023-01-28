#include <thread>
#include <random>
#include <chrono>
#include <iostream>
#include <oneapi/tbb/parallel_for_each.h>
#include <oneapi/tbb/task_arena.h>
#include <fmt/format.h>

#include "mod/mod.hpp"

void Mod::run()
{
    using namespace oneapi;

    for( int i = 0; i < 100; ++i )
        is.push_back( i );

    std::mt19937_64 eng{ std::random_device{}() };

    int maximum_degree_of_parallelism = 4;
    tbb::task_arena arena( maximum_degree_of_parallelism );

    arena.execute(
        [ & ] {
            tbb::parallel_for_each(
                std::begin( is ), std::end( is ),
                [ & ]( int ii ) {
                    std::uniform_int_distribution<> dist{ 1, 5 };
                    auto sec = dist( eng );
                    int worker_index = tbb::this_task_arena::current_thread_index();
                    std::this_thread::sleep_for( std::chrono::seconds{ sec } );
                    std::cout << fmt::format( "{:2}: sleeped {} sec(s) at [{}]\n", ii, sec, worker_index );
                } );
        } );
}