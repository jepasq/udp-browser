#include "NetworkNode.hpp"

#include <iostream> // USES cout and cerr

#include <boost/array.hpp>

NetworkNode::NetworkNode()
{
  try
    {
      // From https://www.developpez.net/forums/d722277/c-cpp/cpp/bibliotheques/boost/boost-asio-ecouter-port-udp/#post4192089
      boost::asio::io_service io_service;
      /*      udp::endpoint endpoint (boost::asio::ip::address::from_string("134.246.151.185"), 10001);
      udp::endpoint sender;
      
      udp::socket socket(io_service);
      socket.open(udp::v4());
      socket.bind(endpoint); // <------
      
      boost::array<char, 128> recv_buf;
      size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender);
      
      std::cout.write(recv_buf.data(), len);
      */
      
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
}

NetworkNode::~NetworkNode()
{

}
