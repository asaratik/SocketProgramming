Complete work contains four files named:
-->server_tcp.cpp
-->client_tcp.cpp
-->server_udp.cpp
-->client_upd.cpp

Execution of the files is as shown below:
-->./server port
-->./client host port
-->./server port packetSize sleepTime
-->./client host port packetSize

TCP Server:
-->The TCP/IP server basically creates server instance which listens to port specified as an argument and waits for a client to connect to it.
-->Once a client connects to it and sends a message it prints the details of the client to its standard error and the message received to its standard output.
-->And continues to listen as long as the client sends data.
-->Once the client is done and disconnects, server closes the sockets and exits.
-->If the data is piped from a file then the server detects the end of file and closes the connection.

TCP client:
-->The TCP client connects to a given TCP server and starts the conversation.
-->Once done terminates the connection with the server.
-->The buffer size for the TCP server and client communication is hard coded to 1024.

UPD Server:
-->The UDP server creates a server instance which listens to port specified as argument.
-->Once it receives a message from the client it goes to sleep for a specified time (in milli secs) and then sends an acknowledgement back to the client with a sequence number of the message. 
-->It repeats the same for 30 messages, closes the connection and then exits.

UPD Client:
-->The UDP client creates a client instance which sends 30 messages of specified size to the server and waits for the acknowledgements
-->Calculates the throughput for the execution and displays it on the standard output.


References:
http://www.cplusplus.com, Linux manual for attributes and command usage.