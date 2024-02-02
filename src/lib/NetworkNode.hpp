#ifndef __NETWORK_NODE_HPP__
#define __NETWORK_NODE_HPP__

#include <boost/asio.hpp>

/** A Node in the overall P2P network.
  *
  */
class NetworkNode
{
public:
  NetworkNode();
  ~NetworkNode();

  // Not sure for the return type yet
  void download(std::string  = "134.246.151.185", int = 10001);

private:
  boost::asio::io_service io_service; //!< The asio (i.e. network) service
  
  // A download URL function 
};

#endif // !__NETWORK_NODE_HPP__
