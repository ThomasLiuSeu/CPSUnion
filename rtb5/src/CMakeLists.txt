
INCLUDE_DIRECTORIES(../) 

SET(SOURCE_FILES rtb5_server.cc)

LINK_DIRECTORIES(/usr/include /usr/local/include  ${BASE_PATH}/lib)

ADD_LIBRARY(database database.cc)

TARGET_LINK_LIBRARIES(database campaign_pb union_pb click_pb mysqlclient boost_system)

ADD_LIBRARY(http_client http_client.cc)

TARGET_LINK_LIBRARIES(http_client campaign_pb union_pb click_pb mysqlclient boost_system)

ADD_LIBRARY(click_processor click_processor.cc)

TARGET_LINK_LIBRARIES(click_processor database campaign_pb union_pb click_pb mysqlclient boost_system)

ADD_LIBRARY(haitao55_order_update_functor haitao55_order_update_functor.cc)

TARGET_LINK_LIBRARIES(haitao55_order_update_functor http_client order_pb)

ADD_LIBRARY(order_update_processor order_update_processor.cc)

TARGET_LINK_LIBRARIES(order_update_processor database haitao55_order_update_functor)

ADD_EXECUTABLE(click_client  click_client.cc )

TARGET_LINK_LIBRARIES(click_client click_pb)

ADD_EXECUTABLE(click_server  click_server.cc)

TARGET_LINK_LIBRARIES(click_server click_pb click_processor -lglog -lgflags)

ADD_EXECUTABLE(admin_server  admin_server.cc)

TARGET_LINK_LIBRARIES(admin_server click_pb user_pb click_processor -lglog -lgflags)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a${CMAKE_FIND_LIBRARY_SUFFIXES})

ADD_EXECUTABLE(order_update  order_update.cc)
 
TARGET_LINK_LIBRARIES(order_update order_update_processor database haitao55_order_update_functor -lglog -lgflags)