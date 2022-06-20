#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <arpa/inet.h>
#include <math.h>

/* Visit website : https://csepracticals.wixsite.com/csepracticals
 * Use following Links to verify the results : 
 * Link 1  : http://www.silisoftware.com/tools/ipconverter.php
 * Link 2  : http://jodies.de/ipcalc
 * 
 * Solution to Assignment
 * Level : Intermediate to Advanced, not for Beginner Programmers
 *
 * How to compile and run : 
 * Compile : gcc -g -c solution.c -o solution.o
 * Link    : gcc -g solution.o -o solution -lm
 * Run     : ./solution
 * */

/*Bit Wise operations
 *
 * You must be familiar with Bitwise operations done
 * in C. Please understand the below Macros
 * */

/*You must know the concept of Big endian and Little Endian Machines
 * and what is the purpose of htonl and ntohl - Important*/

/*Standard Functions suchs as inet_pton and inet_ntop have been used to
 * make life easier. Understand the use of this Function. Google them.*/


/*If you dont understand this assignment solution, you need to work on 
 * your C language*/

#define IS_BIT_SET(n, pos)  ((n & (1 << (pos))) != 0)
#define TOGGLE_BIT(n, pos)  (n = n ^ (1 << (pos)))
#define COMPLEMENT(num)     (num = num ^ 0xFFFFFFFF)
#define UNSET_BIT(n, pos)   (n = n & ((1 << pos) ^ 0xFFFFFFFF))
#define SET_BIT(n, pos)     (n = n | 1 << pos)


#define PREFIX_LEN  15  /*Max length of IP address in A.B.C.D format*/
#define MAX_MASK_LEN 32  /*Maximum mask value in decimal notation*/

/*For example, if mask = 24 is passed as an argument, 
 * function should return an unsigned integer equivalent to 
 * below bit settings
 * 11111111 11111111 11111111 00000000
 * */
static unsigned int
get_mask_value_in_integer_format(char mask_value){

    unsigned int mask = 0xFFFFFFFF;
    char n_trail_bits = MAX_MASK_LEN - mask_value;
    int i = 0;
    for(; i < n_trail_bits; i++){
        UNSET_BIT(mask, i);
    }
    return mask;
}

void
get_broadcast_address(char *ip_addr, char mask, char *output_buffer){
    
    unsigned int ip_addr_integer = 0;

    /*Convert ip address from A.B.C.D format to equivalent unsigned integer*/
    inet_pton(AF_INET, ip_addr, &ip_addr_integer);
    /* To understand below line, you need to google
     * Little endian and big endian concept*/
    ip_addr_integer =  htonl(ip_addr_integer);

    unsigned int mask_integer_format = get_mask_value_in_integer_format(mask);
    /*if mask_integer_format = 11111111 11111111 11111111 00000000, then below
     * fn would return 00000000 00000000 00000000 11111111*/
    COMPLEMENT(mask_integer_format); /*Revere the bits*/
    /*now, Perform OR-ing*/
    unsigned int broadcast_addr = ip_addr_integer | mask_integer_format;
    broadcast_addr = htonl(broadcast_addr);
    /*convert the broadcast address from interger to A.B.C.D format*/
    inet_ntop(AF_INET, &broadcast_addr, output_buffer, PREFIX_LEN + 1);
    output_buffer[PREFIX_LEN] = '\0';
}

unsigned int get_ip_integer_equivalent(char *ip_address){

    unsigned int ip_addr_integer = 0;
    /*Convert ip address from A.B.C.D format to equivalent unsigned integer*/
    inet_pton(AF_INET, ip_address, &ip_addr_integer);
    return htonl(ip_addr_integer);
}

void get_abcd_ip_format(unsigned int ip_address, char *output_buffer){

    /*Convert an ip address from Integer to A.B.C.D format*/
    inet_ntop(AF_INET, &ip_address, output_buffer, PREFIX_LEN + 1);
    output_buffer[PREFIX_LEN] = '\0';
}

/*Follow the steps explained in the course*/
void get_network_id(char *ip_address, char mask, char *output_buffer){

    unsigned int mask_integer_format = get_mask_value_in_integer_format(mask);
    unsigned int ip_address_integer = 0 ;
    inet_pton(AF_INET, ip_address, &ip_address_integer);
    unsigned int network_id = ip_address_integer & mask_integer_format;
    network_id = htonl(network_id);
    inet_ntop(AF_INET, &network_id, output_buffer, PREFIX_LEN + 1);     
}

unsigned int get_subnet_cardinality(char mask_value){

    return pow(2, MAX_MASK_LEN - mask_value) -2 ;
}

/*Follow the steps explained in the course*/
int /*Return 0 if true, -1 if false*/
check_ip_subnet_membser_ship(char *network_id, char mask, char *check_ip){

    unsigned int check_ip_integer = 0;
    inet_pton(AF_INET, check_ip, &check_ip_integer);
    unsigned int mask_integer = get_mask_value_in_integer_format(mask);
    unsigned int calculated_nw_id = check_ip_integer & mask_integer;
    unsigned int network_id_integer = 0;
    inet_pton(AF_INET, network_id, &network_id_integer);  
    if(network_id_integer == check_ip_integer)
        return 0;
    return -1;
}

int
main(int argc, char **argv){

/*Testing get_broadcast_address()*/
{ 
    printf("Testing Q1..\n");   
    char ip_address[PREFIX_LEN + 1],
         output_buffer[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    char mask = 24;
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    get_broadcast_address(ip_address, mask, output_buffer);
    printf("broadcast address  = %s\n", output_buffer);
    printf("Testing Q1 Done.\n");   
}

/*Testing get_ip_integer_equivalent()*/
{ 
    printf("Testing Q2..\n");   
    char ip_address[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    unsigned int a = get_ip_integer_equivalent(ip_address);
    printf("a = %u\n", a);
    printf("Testing Q2 Done.\n");   
}


/*Testing get_abcd_ip_format()*/
{
    char output_buffer[PREFIX_LEN + 1];
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    unsigned int a = 2058138165; 
    printf("Testing Q3..\n");   
    get_abcd_ip_format(htonl(a), output_buffer);
    printf("IP address in A.B.C.D format = %s\n", output_buffer); 
    printf("Testing Q3 Done.\n");   
}


/*Testing get_network_id()*/
{ 
    printf("Testing Q4..\n");   
    char ip_address[PREFIX_LEN + 1],
         output_buffer[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    char mask = 20;
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    get_network_id(ip_address, mask, output_buffer);
    printf("Network Id = %s/%u\n", output_buffer, mask);
    printf("Testing Q4 Done.\n");   
}

/*Testing get_subnet_cardinality() */
{
    printf("Testing Q5..\n");    
    char mask = 24;
    printf("Cardinality = %u\n", get_subnet_cardinality(mask));
    printf("Testing Q5 Done.\n");
}

{
/*Testing check_ip_subnet_membser_ship()*/    
    printf("Testing Q6..\n");
    char network_id[PREFIX_LEN + 1];
    strncpy(network_id, "192.168.1.0", strlen("192.168.1.0"));
    network_id[PREFIX_LEN] = '\0';

    char mask = 24;

    char ip_address[PREFIX_LEN + 1];
    strncpy(ip_address, "192.168.1.10",  strlen("192.168.1.10"));

    int res = check_ip_subnet_membser_ship(network_id, mask, ip_address);
    printf("IP Subnet check Result = %s\n", res == 0 ? "Membership true": "Membership false");
    printf("Testing Q6 Done.\n");
}

    return 0;
}   
