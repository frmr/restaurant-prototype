cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(restaurant-prototype)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -lncurses -lm")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(TF_SOURCES
	src/tf/src/tfTextFile.cpp
	src/tf/src/tfString.cpp
	src/tf/src/tfTimer.cpp
)

set(RP_SOURCES
	src/restaurant-prototype/main.cpp
	src/restaurant-prototype/rpColorPair.cpp
	src/restaurant-prototype/rpVec2.cpp
	src/restaurant-prototype/rpApp.cpp
	src/restaurant-prototype/rpEntity.cpp
	src/restaurant-prototype/rpPlayer.cpp
	src/restaurant-prototype/rpSimulation.cpp
	src/restaurant-prototype/rpInputs.cpp
	src/restaurant-prototype/rpBufferedInput.cpp
	src/restaurant-prototype/rpCustomerQueue.cpp
	src/restaurant-prototype/rpCustomer.cpp
	src/restaurant-prototype/rpSeat.cpp
)

add_executable(restaurant-prototype
	${TF_SOURCES}
	${RP_SOURCES}
)

target_include_directories(restaurant-prototype PUBLIC
	src/tf/src
)

target_link_libraries(restaurant-prototype ncurses)
