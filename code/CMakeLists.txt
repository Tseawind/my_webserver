# set (SRC_LIST 
#     ${PROJECT_SOURCE_DIR}/buffer/buffer.cpp
#     ${PROJECT_SOURCE_DIR}/http/httpconn.cpp
#     ${PROJECT_SOURCE_DIR}/http/httprequest.cpp
#     ${PROJECT_SOURCE_DIR}/http/httpresponse.cpp
#     ${PROJECT_SOURCE_DIR}/log/log.cpp
#     ${PROJECT_SOURCE_DIR}/pool/sqlconnpool.cpp
#     ${PROJECT_SOURCE_DIR}/server/epoller.cpp
#     ${PROJECT_SOURCE_DIR}/server/webserver.cpp
#     ${PROJECT_SOURCE_DIR}/timer/heaptimer.cpp)

add_library(my-webserver SHARED 
            ${PROJECT_SOURCE_DIR}/code/buffer/buffer.cpp
            ${PROJECT_SOURCE_DIR}/code/http/httpconn.cpp
            ${PROJECT_SOURCE_DIR}/code/http/httprequest.cpp
            ${PROJECT_SOURCE_DIR}/code/http/httpresponse.cpp
            ${PROJECT_SOURCE_DIR}/code/log/log.cpp
            ${PROJECT_SOURCE_DIR}/code/pool/sqlconnpool.cpp
            ${PROJECT_SOURCE_DIR}/code/server/epoller.cpp
            ${PROJECT_SOURCE_DIR}/code/server/webserver.cpp
            ${PROJECT_SOURCE_DIR}/code/timer/heaptimer.cpp
            )
