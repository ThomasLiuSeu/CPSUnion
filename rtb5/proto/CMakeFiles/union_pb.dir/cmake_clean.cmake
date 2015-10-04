FILE(REMOVE_RECURSE
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
  "CMakeFiles/union_pb.dir/union.pb.cc.o"
  "../lib/libunion_pb.pdb"
  "../lib/libunion_pb.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/union_pb.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
