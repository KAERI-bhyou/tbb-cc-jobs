#include <iostream>

#include "mod/mod.hpp"

void Mod::run()
{
    tbb::parallel_for( 0, 20, [ & ]( int i ) { queue.push( i ); } );

    int num = 0;
    while( queue.try_pop( num ) )
        std::cout << num << " ";
}