/*
 * Copyright (c) 2009 Intel Corporation.  All rights reserved.
 *
 * This software is available to you under the OpenIB.org BSD license
 * below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AWV
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LIBACM_H
#define LIBACM_H

#include <infiniband/acm.h>

int ib_acm_connect(char *dest_svc);
void ib_acm_disconnect();

int ib_acm_resolve_name(char *src, char *dest,
	struct ibv_path_data **paths, int *count, uint32_t flags);
int ib_acm_resolve_ip(struct sockaddr *src, struct sockaddr *dest,
	struct ibv_path_data **paths, int *count, uint32_t flags);
int ib_acm_resolve_path(struct ibv_path_record *path, uint32_t flags);
#define ib_acm_free_paths(paths) free(paths)

int ib_acm_query_perf(uint64_t **counters, int *count);
#define ib_acm_free_perf(counters) free(counters)

#endif /* LIBACM_H */
