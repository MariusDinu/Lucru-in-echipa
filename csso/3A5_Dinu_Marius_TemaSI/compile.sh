g++ bNode.cpp UtilCrypto.cpp UtilSocket.cpp -o node_B -lcrypto
g++ aNode.cpp UtilCrypto.cpp UtilSocket.cpp -o node_A -lcrypto
g++ main.cpp UtilCrypto.cpp UtilSocket.cpp -o node_KM -lcrypto
