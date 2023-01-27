#include <thread>
#include <random>
#include <chrono>
#include <iostream>
#include <tbb/parallel_for_each.h>
#include <tbb/task_arena.h>
#include <fmt/format.h>

#include "mod/mod.hpp"

void Mod::run()
{
    for( int i = 0; i < 100; ++i )
        is.push_back( i );

    std::mt19937_64 eng{ std::random_device{}() }; // or seed however you want
    tbb::task_arena arena( 4 );

    arena.execute(
        [ & ]
        {
            tbb::parallel_for_each( std::begin( is ), std::end( is ),
                                    [ & ]( int ii )
                                    {
                                        std::uniform_int_distribution<> dist{ 1, 5 };
                                        auto sec = dist( eng );
                                        int worker_index = tbb::this_task_arena::current_thread_index();
                                        std::this_thread::sleep_for( std::chrono::seconds{ sec } );
                                        std::cout << fmt::format( "{:2}: sleeped {} sec(s) at [{}]\n", ii, sec, worker_index );
                                    } );
        } );
}