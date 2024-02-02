#include "NetworkNode.hpp"

#include <iostream> // USES cout and cerr

#include <boost/array.hpp>

/** The NetworkNode constructor
  *
  */
NetworkNode::NetworkNode()
{
}

/** The node destructor
  *
  */
NetworkNode::~NetworkNode()
{

}

/** Download a file from the given distant node
  *
  * \param ip   The I0P adress
  * \param port The network port of the distant node.
  *
  */
void
NetworkNode::download(std::string ip, int port)
{
  using boost::asio::ip::udp;
  
  udp::endpoint sender;
  boost::array<char, 128> recv_buf;
  size_t len;
  
  try
    {
      // From https://www.developpez.net/forums/d722277/c-cpp/cpp/bibliotheques/boost/boost-asio-ecouter-port-udp/#post4192089
      udp::endpoint endpoint (boost::asio::ip::address::from_string(ip), port);
      
      udp::socket socket(io_service);
      socket.open(udp::v4());
      socket.bind(endpoint); // <------
      
      len = socket.receive_from(boost::asio::buffer(recv_buf), sender);
      
      std::cout.write(recv_buf.data(), len);
      
      
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }

}

