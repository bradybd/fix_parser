/**
 * @file   fix_msg.h
 * @author Dmitry S. Melnikov, dmitryme@gmail.com
 * @date   Created on: 07/30/2012 06:28:42 PM
 */

#ifndef FIX_PARSER_FIX_MSG_H
#define FIX_PARSER_FIX_MSG_H

#include "fix_types.h"
#include "fix_parser_dll.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * create new FIX message
 * @param[in] parser - instance of parser
 * @param[in] msgType - type of message (e.g. "A", "D", "AE", etc.)
 * @return pointer to created message, is NULL see fix_parser_get_error_code(parser) for error
 * @note all allocated messages must be destroyed with fix_msg_free
 */
FIX_PARSER_API FIXMsg* fix_msg_create(FIXParser* parser, char const* msgType);
/**
 * free allocated message
 * @param[in] msg - message, which should be destroyed.
 */
FIX_PARSER_API void fix_msg_free(FIXMsg* msg);

/**
 * add new FIX group to tag
 * @param[in] msg - FIX message
 * @param[in] grp - parent group. Can be NULL if group added to message tag, or not null is new nested group should be
 * created
 * @param[in] tagNum - field tag in which new group will be added
 * @return pointer to new group, if NULL, see fix_parser_get_error_code(parser)
 */
FIX_PARSER_API FIXGroup* fix_msg_add_group(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum);
/**
 * get group by zero-based index
 * @param[in] msg - message with requested group
 * @param[in] grp - parent group, in case in nested group requested. Can be NULL.
 * @param[in] tagNum - field tag with requested group
 * @param[in] grpIdx - zero-based index of requested group
 * @return requested group, if NULL see fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXGroup* fix_msg_get_group(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, uint32_t grpIdx);
/**
 * delete group by zero-based index
 * @param[in] msg - FIX message
 * @param[in] grp - parent group, if deleted group is a nested one, else can be NULL.
 * @param[in] tagNum - field tag with deleted group
 * @param[in] grpIdx - zero-based index of deleted group
 * @return FIX_SUCCESS - is OK, FIX_FAILED - something goes wrong. See fix_parser_get_error_code(parser) for details
 * */
FIX_PARSER_API FIXErrCode fix_msg_del_group(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, uint32_t grpIdx);

/**
 * set tag with string value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] val - string value (ends with zero)
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_string(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char const* val);

/**
 * set tag with 32-bit numeric value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] val - 32-bit numeric value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_int32(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, int32_t val);

/**
 * set tag with 64-bit numeric value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] val - 64-bit numeric value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_int64(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, int64_t val);

/**
 * set tag with single char value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] val - char value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_char(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char val);

/**
 * set tag with double value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] val - double value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_double(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, double val);

/**
 * set tag with data value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[in] data - data value
 * @param[in] dataLen - data value length
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_set_data(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char const* data, uint32_t dataLen);

/**
 * get tag 32-bit value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - requested value. Pointer to sizeof(int32_t) allocated space required.
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_int32(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, int32_t* val);

/**
 * get tag 64-bit value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - requested value. Pointer to sizeof(int64_t) allocated space required.
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_int64(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, int64_t* val);

/**
 * get tag double value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - requested value. Pointer to sizeof(double) allocated space required.
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_double(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, double* val);

/**
 * get tag char value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - requested value. Pointer to sizeof(char) allocated space required.
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_char(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char* val);

/**
 * get tag string value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - pointer to requested value
 * @param[out] len - length of requested value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_string(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char const** val, uint32_t* len);

/**
 * get tag data value
 * @param[in] msg - FIX message
 * @param[in] grp - non NULL group, if tag is a part of group, else must be NULL
 * @param[in] tagNum - field tag number
 * @param[out] val - pointer to requested value
 * @param[out] len - length of requested value
 * @return FIX_SUCCESS - OK, FIX_FAILED - not set. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_get_data(FIXMsg* msg, FIXGroup* grp, FIXTagNum tagNum, char const** val, uint32_t* len);

/**
 * delete field from message
 * @param[in] msg - message with tag, which will be deleted
 * @param[in] grp - not NULL group pointer, if tag is a part of group, else must be NULL
 * @param[in] tag - field tag, which should be removed
 * @return FIX_SUCCESS - OK, FIX_FAILED - deletion failed. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_del_field(FIXMsg* msg, FIXGroup* grp, FIXTagNum tag);

/**
 * convert message to FIX format
 * @param[in] msg - message to be converted
 * @param[in] delimiter - FIX field delimter char
 * @param[out] buff - buffer with converted message
 * @param[out] buffLen - length of output buffer
 * @param[out] reqBuffLen - if buff length too small, reqBuffLen returns length of needed space
 * @return FIX_SUCCESS - OK, FIX_FAILED - convertion failed. See fix_parser_get_error_code(parser) for details
 */
FIX_PARSER_API FIXErrCode fix_msg_to_fix(FIXMsg* msg, char delimiter, char* buff, uint32_t buffLen, uint32_t* reqBuffLen);

#ifdef __cplusplus
}
#endif

#endif /* FIX_PARSER_FIX_MSG_H */
