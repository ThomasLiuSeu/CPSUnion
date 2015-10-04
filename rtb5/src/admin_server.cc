/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <glog/logging.h> 
#include <gflags/gflags.h> 

#include "proto/click.grpc.pb.h"
#include "src/click_processor.h"

int main(int argc, char** argv) {

  ::google::InitGoogleLogging(argv[0]); 
  ::google::ParseCommandLineFlags(&argc, &argv, true);
  Database database;
  database.Open();
  Union haitao55;
  haitao55.set_union_id(1);
  haitao55.set_union_name("55haitao");
  haitao55.set_url_pattern("http://union.55haitao.com/index.php?mod=go"
      "&op=multiple&token=ZhZIC5HluW3vVdlO&url={origin_url}&tags={tags}");
  Union viglink;
  viglink.set_union_id(2);
  viglink.set_union_name("viglink");
  viglink.set_url_pattern("http://union.viglink.com/index.php?mod=go"
      "&op=multiple&token=ZhZIC5HluW3vVdlO&url={origin_url}&tags={tags}");

  User user;
  user.set_user_id(3);
  user.set_user_name("chanet");
  user.set_password("abcdefg2008");
  user.set_token("3123ads");
  user.set_account("account");

  Campaign campaign;
  campaign.set_campaign_id(1);
  campaign.set_union_id(1);
  campaign.set_campaign_name("6pm");
  campaign.set_pattern("baidu");
  campaign.set_percent(0.07);
  database.Insert(haitao55);
  database.Insert(viglink);
  database.Insert(campaign);
  campaign.set_campaign_id(2);
  campaign.set_union_id(2);
  campaign.set_campaign_name("yama");
  campaign.set_pattern("qq");
  campaign.set_percent(0.06);
  database.Insert(campaign);
  database.Insert(user);

}