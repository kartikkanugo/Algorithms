include_directories(include)


add_library(kkdivideandconquer kkdivideandconquer.cpp include/kkdivideandconquer.h 
								kkdatastructures.cpp include/kkdatastructures.h 
								kksortsearch.cpp include/kksortsearch.h )
add_library(kkalgorithms kkalgorithms.cpp include/kkalgorithms.h)