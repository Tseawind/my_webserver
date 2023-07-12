add_executable(server main.cpp)
target_link_libraries(server my-webserver)
target_link_libraries(server mysqlclient)