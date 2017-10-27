/*
 * twemproxy - A fast and lightweight proxy for memcached protocol.
 * Copyright (C) 2011 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sys/stat.h>
#include <sys/un.h>

#include <nc_core.h>
#include <nc_server.h>
#include <nc_notify.h>
#include <nc_proxy.h>

rstatus_t notify_recv(struct context *ctx, struct conn *conn){
	//exit(1);
    //sleep(1);
    rstatus_t status = array_each(&ctx->pool, proxy_each_remove, NULL);
    if (status != NC_OK) {
    }
    ctx->close = 1;
    ctx->close_time = (int64_t)time(NULL);
    return NC_OK;
}

rstatus_t notify_init(struct context *ctx,int fd){
	rstatus_t status;

    struct conn *conn;

    struct server_pool *pool = array_get(&ctx->pool,0);

    conn = conn_get_notify(pool);
    if (conn == NULL) {
        return NULL;
    }
    conn->sd = fd;
    
    status = event_add_conn(ctx->evb, conn);
    if(status < 0){

    }
    status = event_del_out(ctx->evb, conn);
    if(status < 0){

    }
    return NC_OK;
}