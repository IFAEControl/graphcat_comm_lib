#include <iostream>

#ifdef _WIN32
#pragma once
#include <winsock.h>
#else
#include <arpa/inet.h>
#endif

#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>
#include <nlohmann/json.hpp>


#include "graphcat-lib.hpp"
#include "header.hpp"

using Poco::Net::IPAddress;
using json = nlohmann::json;

// TODO: Ejemplo de una función de biblioteca
void fngraphcatlib()
{
  //const HostEntry& entry = DNS::hostByName("www.appinf.com");
}

int test() {
    json j;
    
    j["command"] = "example.ping_pong";
    j["answer"] = json{};
    json args;
    args["ping"] = 0xdeadbeef;
    j["arguments"] = args;
    auto buf = j.dump();
    
    BaseHeaderType h{};
    h.packtype = HEADER_PACKTYPE::COMMAND;
    h.data_rate = htonl(123);
    h.packetsize = htonl(buf.size());
    
    Poco::Net::SocketAddress sa("127.0.0.1", 32000);
    Poco::Net::StreamSocket socket(sa);
    //socket.sendBytes(&h, HEADER_BYTE_SIZE);
    Poco::Net::SocketStream str(socket);
    str << h;
    str << j;
    str.flush();
    Poco::StreamCopier::copyStream(str, std::cout);
    return 0;
}
