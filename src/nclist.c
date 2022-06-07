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

    while (ifaddress) {
        int family = ifaddress->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {
            printf("%s:\t", ifaddress->ifa_name);
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

            char host[MAXHOST];

            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(ifaddress->ifa_addr, family_size, host, MAXHOST, NULL, 0, NI_NUMERICHOST);

            printf("%s\n", host);
        }

        ifaddress = ifaddress->ifa_next;
    }
}