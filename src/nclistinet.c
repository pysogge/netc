// nclist.c
// list local hosts

#include <ifaddrs.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

#define MAXHOST 128

int main() {
    struct ifaddrs *ifaddresses, *ifaddress;

    if (getifaddrs(&ifaddresses) == -1) {
        perror("getifaddrs call failed");
        return -1;
    }

    ifaddress = ifaddresses;

    while(ifaddress != NULL) {
        if (ifaddress->ifa_addr != NULL && ifaddress->ifa_addr->sa_family == AF_INET) {
            char host[MAXHOST];
            getnameinfo(ifaddress->ifa_addr, sizeof(struct sockaddr_in), host, MAXHOST, NULL, 0, NI_NUMERICHOST);
            printf("%s\n", host);
        }
        ifaddress = ifaddress->ifa_next;
    }

}