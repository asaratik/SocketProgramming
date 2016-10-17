#include "common.h"
using namespace std;
using namespace std::chrono;
 
int main(int argc, char *argv[])
{
	if(argc < 4)
	{
        cout << "Expected execution : ./client host port packetSize" << endl;
		return 0;
	}

    int sckt,bufferSize = atoi(argv[3]);
    char message[bufferSize];
    char buffer[bufferSize];
    uint i;
    string inputString;
    struct hostent *remoteHost;
    struct sockaddr_in server_addr;
    socklen_t size = sizeof(server_addr); 
    int count = 0;
    sckt = socket(AF_INET, SOCK_DGRAM, 0);
    double throughPut,duration;

    if (sckt < 0)
    {
        perror("Error establishing a socket !!");
        return 0;
    }

    remoteHost = gethostbyname(argv[1]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    bcopy((char *)remoteHost->h_addr,(char *)&server_addr.sin_addr,remoteHost->h_length);
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    while(count < 30)
    {
        memset(buffer,0,strlen(buffer));
        memset(message,0,strlen(message));
		inputString = "Packet " + to_string(count);
		for(i=0;i<inputString.size();i++){
        message[i]=inputString[i];
		}
		sendto(sckt,message,bufferSize,0,(struct sockaddr *) &server_addr, size);
        recvfrom(sckt,buffer,bufferSize,0,(struct sockaddr *) &server_addr, &size);
        cout <<"Server : "<< buffer << endl;
		count++;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>( t2 - t1 ).count();

    throughPut = (30000*bufferSize)/duration;
    
    cout << "ThroughPut for the execution : " << throughPut << endl;
    close(sckt);
    return 0;
}
