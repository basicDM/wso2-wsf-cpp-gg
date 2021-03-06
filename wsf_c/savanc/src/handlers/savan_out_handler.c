/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
#include <axis2_addr_mod.h>
#include <axis2_addr.h>
*/
#include <axis2_handler_desc.h>
#include <axutil_array_list.h>
#include <axiom_soap_const.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header_block.h>
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_msg_info_headers.h>
#include <axutil_property.h>

#include <savan_constants.h>
#include <savan_error.h>
#include <savan_sub_processor.h>
#include <savan_util.h>
#include <savan_msg_recv.h>
#include <savan_subscriber.h>
#include <savan_subs_mgr.h>

axis2_status_t AXIS2_CALL
savan_out_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
savan_out_handler_create(
    const axutil_env_t *env, 
    axutil_qname_t *qname) 
{
    axis2_handler_t *handler = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    /* handler init is handled by conf loading, so no need to do it here */
    
    /* set the base struct's invoke op */
	axis2_handler_set_invoke(handler, env,savan_out_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
savan_out_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    savan_subs_mgr_t *subs_mgr = NULL;

    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);


    subs_mgr = savan_subs_mgr_get_subs_mgr(env, conf_ctx, conf);
    if(!subs_mgr)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Could not create the database. Check \
            whether database path is correct and accessible. Exit loading the Savan module");
        AXIS2_HANDLE_ERROR(env, SAVAN_ERROR_DATABASE_CREATION_ERROR, AXIS2_FAILURE);

        return AXIS2_FAILURE;
    }

    return status;
}

