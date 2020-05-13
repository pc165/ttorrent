#ifndef SERVER_H
#define SERVER_H
#include "file_io.h"
#include <stdint.h>

/**
 * Create a socket and bind it to INADDR_ANY:port 
 * @param port port to listen * 
 * @return socket descriptor or -1 on error
 */
int server__init_socket(const uint16_t port);

/**
 * Manage a non-blocking socket, must be used after calling server__init_socket
 * @param sockd A descriptor to a non blocking socket 
 * @param t pointer to struct created with fio_create_torrent_from_metainfo_file
 * @return 0 if no error or -1 if error 
 */
int server__non_blocking(const int sockd, struct fio_torrent_t *const t);

/**
 * Manage a blocking socket, must be used after calling server__init_socket
 * @param sockd A descriptor to a blocking socket 
 * @return 0 if no error or -1 if error 
 */
int server__blocking(const int sockd);

/**
 * Your kill switch
 * The struct pointers maybe NULL.
 * @param sockd A descriptor to a blocking socket 
 * @return Doesn't return.
 */
void server__die(char *file_name, int ile_line, struct utils_array_pollfd_t *d, struct utils_array_pollfd_t *p);

/**
 * Main function
 * @param port the port to listen to 
 * @return 0 if everything went correctly or -1 if error
 * @param metainfo name of the torrent file, must have the extension .ttorrent and must be in the same directory
 */
int server_init(const uint16_t port, const char *const metainfo);

#endif