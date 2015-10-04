// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: click.proto
#ifndef GRPC_click_2eproto__INCLUDED
#define GRPC_click_2eproto__INCLUDED

#include "click.pb.h"

#include <grpc++/support/async_stream.h>
#include <grpc++/impl/rpc_method.h>
#include <grpc++/impl/proto_utils.h>
#include <grpc++/impl/service_type.h>
#include <grpc++/support/async_unary_call.h>
#include <grpc++/support/status.h>
#include <grpc++/support/stub_options.h>
#include <grpc++/support/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace RTB5 {

class ClickService GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Process(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::RTB5::ClickResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RTB5::ClickResponse>> AsyncProcess(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RTB5::ClickResponse>>(AsyncProcessRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::RTB5::ClickResponse>* AsyncProcessRaw(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::Channel>& channel);
    ::grpc::Status Process(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::RTB5::ClickResponse* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RTB5::ClickResponse>> AsyncProcess(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RTB5::ClickResponse>>(AsyncProcessRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::Channel> channel_;
    ::grpc::ClientAsyncResponseReader< ::RTB5::ClickResponse>* AsyncProcessRaw(::grpc::ClientContext* context, const ::RTB5::ClickRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Process_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::Channel>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::SynchronousService {
   public:
    Service() : service_(nullptr) {}
    virtual ~Service();
    virtual ::grpc::Status Process(::grpc::ServerContext* context, const ::RTB5::ClickRequest* request, ::RTB5::ClickResponse* response);
    ::grpc::RpcService* service() GRPC_OVERRIDE GRPC_FINAL;
   private:
    ::grpc::RpcService* service_;
  };
  class AsyncService GRPC_FINAL : public ::grpc::AsynchronousService {
   public:
    explicit AsyncService();
    ~AsyncService() {};
    void RequestProcess(::grpc::ServerContext* context, ::RTB5::ClickRequest* request, ::grpc::ServerAsyncResponseWriter< ::RTB5::ClickResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag);
  };
};

}  // namespace RTB5


#endif  // GRPC_click_2eproto__INCLUDED