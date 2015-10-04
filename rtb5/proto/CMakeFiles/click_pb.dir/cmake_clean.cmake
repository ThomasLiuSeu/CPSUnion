FILE(REMOVE_RECURSE
  "click.grpc.pb.h"
  "click.grpc.pb.cc"
  "proto"
  "click.pb.h"
  "click.pb.cc"
  "campaign.pb.h"
  "campaign.pb.cc"
  "union.pb.h"
  "union.pb.cc"
  "user.pb.h"
  "user.pb.cc"
  "order.pb.h"
  "order.pb.cc"
  "proto"
  "CMakeFiles/click_pb.dir/click.grpc.pb.cc.o"
  "CMakeFiles/click_pb.dir/click.pb.cc.o"
  "../lib/libclick_pb.pdb"
  "../lib/libclick_pb.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/click_pb.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
