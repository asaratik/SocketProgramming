#include "common.h"

using namespace std; 

int main(int argc, char *argv[])
{
   if(argc < 4)
	{
        cout << "Expected execution : ./server port packetSize sleepTime" << endl;
		return 0;
	}

	int count = 0,received,sent;
    int portNumber = atoi(argv[1]),sleepTime = atoi(argv[3]),sckt,bufferSize = atoi(argv[2]);
	char buffer[bufferSize];
	uint i;
    char message[bufferSize];
	struct sockaddr_in server_addr,client_addr;
    string dataToSend;
    socklen_t size = sizeof(server_addr);    
    sckt = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNumber);


    if ((bind(sckt, (struct sockaddr*)&server_addr,size)) < 0)
    {
        perror("Error binding the connection !!");
        return 0;
    }

    cout << "Waiting for connections..." << endl;     

    
    while(count < 30)
    {
    cout <<"--------------------------------------------------------------------------------"<<endl;
    memset(message,0,bufferSize);
    received = recvfrom(sckt , message , bufferSize , 0 , (struct sockaddr *) &client_addr,&size);    
    if(received <0)
        {
            perror("Error receiving data !!");
            return 0;
        }
	cout << "Client :" <<message<< endl;
    usleep(sleepTime*1000);

    dataToSend = "Packet " + to_string(count) + " received.";
    cout << "Received packet : "<<count<<", acknowledging client..."<< endl ;

    memset(buffer,0,bufferSize);

    for(i=0;i<dataToSend.size();i++){
        buffer[i]=dataToSend[i];
    }

    sent = sendto(sckt,buffer,bufferSize,0,(struct sockaddr *) &client_addr,sizeof(client_addr));
    cout << "Data sent : " << sent <<" bytes, Data received : " << received <<" bytes." << endl;
    count++;
    cout <<"--------------------------------------------------------------------------------"<<endl;
    }
    
    close(sckt);
    return 0;
}