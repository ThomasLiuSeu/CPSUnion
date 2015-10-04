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

#include <grpc++/grpc++.h>

#include "proto/click.grpc.pb.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using namespace RTB5;
using RTB5::ClickRequest;
using RTB5::ClickResponse;
using RTB5::ClickService;

class ClickClient {
 public:
  ClickClient(std::shared_ptr<Channel> channel)
      : stub_(ClickService::NewStub(channel)) {}

  // Assambles the client's payload, sends it and presents the response back
  // from the server.
  std::string Process() {
    // Data we are sending to the server.
    ClickRequest request;
    request.set_user_id(3);
    request.set_tags("temp");
    request.set_origin_url("www.taobao.com");

    // Container for the data we expect from the server.
    ClickResponse response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->Process(&context, request, &response);

    // Act upon its status.
    if (status.ok()) {
      return response.second_jump_url();
    } else {
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<ClickService::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureCredentials()).
  ClickClient ClickService(
      grpc::CreateChannel("localhost:50051", grpc::InsecureCredentials()));
  std::string response = ClickService.Process();
  std::cout << "ClickService received: " << response << std::endl;

  return 0;
}
