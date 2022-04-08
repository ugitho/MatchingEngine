add_subdirectory(AuctionAlgorithm/src)

set(PROJECT_SRC
    main.cpp)

add_executable(main ${PROJECT_SRC})

target_link_libraries(main
                      PRIVATE AuctionAlgorithm)
