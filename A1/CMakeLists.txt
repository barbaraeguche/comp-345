# create executable for A1
add_executable(warzone_game_a1
	src/MainDriver.cpp
	src/Map.cpp
	drivers/MapDriver.cpp
	src/Player.cpp
	drivers/PlayerDriver.cpp
	src/Orders.cpp
	drivers/OrdersDriver.cpp
	src/Cards.cpp
	drivers/CardsDriver.cpp
	src/GameEngine.cpp
	drivers/GameEngineDriver.cpp
)

# headers from other directories
target_include_directories(warzone_game_a1 PRIVATE include)

# change compiler warning level
target_compile_options(warzone_game_a1 PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W3 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Werror>
)