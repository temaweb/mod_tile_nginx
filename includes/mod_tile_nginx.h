//
//  mod_tile_nginx.h
//  ngx_http_mod_tile_module
//
//  Created by Артём Оконечников on 23.05.2020.
//  Copyright © 2020 Артём Оконечников. All rights reserved.
//

#ifndef mod_tile_nginx_h
#define mod_tile_nginx_h

typedef struct
{
    /*
     * Turn mod_tile enable
     */
    ngx_flag_t enable;
    
    /*
     * Set name of tile cache directory
     */
    ngx_str_t tile_dir;
    
    /*
     * Set name of the xml config
     */
    ngx_str_t xml_config;
    
    /*
     * Set name of unix domain socket for connecting to rendering daemon
     */
    ngx_str_t renderd_socket_name;
    
    /*
     * Set renderd socket port
     */
    ngx_uint_t renderd_socket_port;
    
    /*
     * Set timeout in seconds on mod_tile requests
     */
    ngx_uint_t request_timeout;
    
    /*
     * Set timeout in seconds on missing mod_tile requests
     */
    ngx_uint_t request_timeout_priority;
    
} mod_tile_server_conf;

static void * ngx_http_mod_tile_create_conf(ngx_conf_t * cf);
static char * ngx_http_mod_tile_merge_conf(ngx_conf_t *cf, void *parent, void *child);

static ngx_int_t ngx_http_mod_tile_init(ngx_conf_t * cf);
static ngx_int_t ngx_http_mod_tile_handler(ngx_http_request_t *r);

static ngx_int_t ngx_http_mod_tile_send_file(ngx_http_request_t * request, unsigned char * buffer, int length);
static ngx_int_t ngx_http_mod_tile_process_request(ngx_http_request_t * request, mod_tile_server_conf * conf, struct protocol * cmd);

static int socket_init(mod_tile_server_conf * conf, ngx_log_t * log);
static int unix_socket_init(mod_tile_server_conf * conf, ngx_log_t * log);
static int tcp_socket_init(mod_tile_server_conf * conf, ngx_log_t * log);

#endif /* mod_tile_nginx_h */